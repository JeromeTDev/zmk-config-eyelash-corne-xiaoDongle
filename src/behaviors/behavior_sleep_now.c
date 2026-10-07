/*
 * Copyright (c) 2026 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#define DT_DRV_COMPAT zmk_behavior_sleep_now

#include <zephyr/device.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/poweroff.h>

#include <drivers/behavior.h>

#include <zmk/behavior.h>
#include <zmk/pm.h>
#if IS_ENABLED(CONFIG_USB_DEVICE_STACK)
#include <zmk/usb.h>
#endif

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

struct behavior_sleep_now_config {
    uint32_t hold_time_ms;
};

struct behavior_sleep_now_data {
    uint32_t press_start;
};

static int on_keymap_binding_pressed(struct zmk_behavior_binding *binding,
                                     struct zmk_behavior_binding_event event) {
    const struct device *dev = zmk_behavior_get_binding(binding->behavior_dev);
    struct behavior_sleep_now_data *data = dev->data;

    data->press_start = k_uptime_get();

    return ZMK_BEHAVIOR_OPAQUE;
}

static int on_keymap_binding_released(struct zmk_behavior_binding *binding,
                                      struct zmk_behavior_binding_event event) {
    const struct device *dev = zmk_behavior_get_binding(binding->behavior_dev);
    struct behavior_sleep_now_data *data = dev->data;
    const struct behavior_sleep_now_config *config = dev->config;

    if (k_uptime_get() - data->press_start < config->hold_time_ms) {
        return ZMK_BEHAVIOR_OPAQUE;
    }

#if IS_ENABLED(CONFIG_USB_DEVICE_STACK)
    // Never sleep while powered by USB (e.g. a dongle acting as central).
    if (zmk_usb_is_powered()) {
        LOG_DBG("USB powered, skipping sleep");
        return ZMK_BEHAVIOR_OPAQUE;
    }
#endif

#if IS_ENABLED(CONFIG_ZMK_PM_DEVICE_SUSPEND_RESUME) && IS_ENABLED(CONFIG_POWEROFF)
    if (IS_ENABLED(CONFIG_ZMK_SPLIT_ROLE_CENTRAL)) {
        // Allow BLE transport to flush the release to the peripherals first.
        k_sleep(K_MSEC(100));
    }

    int err = zmk_pm_suspend_devices();
    if (err < 0) {
        LOG_ERR("Failed to suspend devices (%d)", err);
        zmk_pm_resume_devices();
        return ZMK_BEHAVIOR_OPAQUE;
    }

    LOG_DBG("Triggering deep sleep via sleep_now behavior");
    sys_poweroff();
#endif

    return ZMK_BEHAVIOR_OPAQUE;
}

static const struct behavior_driver_api behavior_sleep_now_driver_api = {
    .binding_pressed = on_keymap_binding_pressed,
    .binding_released = on_keymap_binding_released,
    .locality = BEHAVIOR_LOCALITY_GLOBAL,
#if IS_ENABLED(CONFIG_ZMK_BEHAVIOR_METADATA)
    .get_parameter_metadata = zmk_behavior_get_empty_param_metadata,
#endif
};

#define SLEEP_NOW_INST(n)                                                                          \
    static struct behavior_sleep_now_data data_##n = {};                                           \
    static const struct behavior_sleep_now_config config_##n = {                                   \
        .hold_time_ms = DT_INST_PROP_OR(n, hold_time_ms, 100),                                     \
    };                                                                                             \
    BEHAVIOR_DT_INST_DEFINE(n, NULL, NULL, &data_##n, &config_##n, POST_KERNEL,                    \
                            CONFIG_KERNEL_INIT_PRIORITY_DEFAULT,                                   \
                            &behavior_sleep_now_driver_api);

DT_INST_FOREACH_STATUS_OKAY(SLEEP_NOW_INST)