/*
 * Copyright (c) 2026 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#define DT_DRV_COMPAT zmk_behavior_reset_now

#include <zephyr/device.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/reboot.h>

#include <drivers/behavior.h>

#include <zmk/behavior.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

struct behavior_reset_now_config {
    uint32_t hold_time_ms;
};

struct behavior_reset_now_data {
    uint32_t press_start;
};

static int on_keymap_binding_pressed(struct zmk_behavior_binding *binding,
                                     struct zmk_behavior_binding_event event) {
    const struct device *dev = zmk_behavior_get_binding(binding->behavior_dev);
    struct behavior_reset_now_data *data = dev->data;

    data->press_start = k_uptime_get();

    return ZMK_BEHAVIOR_OPAQUE;
}

static int on_keymap_binding_released(struct zmk_behavior_binding *binding,
                                      struct zmk_behavior_binding_event event) {
    const struct device *dev = zmk_behavior_get_binding(binding->behavior_dev);
    struct behavior_reset_now_data *data = dev->data;
    const struct behavior_reset_now_config *config = dev->config;

    // Require the key to be held down to avoid accidental resets.
    if (k_uptime_get() - data->press_start < config->hold_time_ms) {
        return ZMK_BEHAVIOR_OPAQUE;
    }

#if IS_ENABLED(CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
    // The central forwards this behavior to every peripheral (locality GLOBAL).
    // Keep the central itself running so it can immediately accept reconnects.
    return ZMK_BEHAVIOR_OPAQUE;
#else
    LOG_DBG("Soft reset via reset_now behavior");
    sys_reboot(SYS_REBOOT_WARM);
    return ZMK_BEHAVIOR_OPAQUE;
#endif
}

static const struct behavior_driver_api behavior_reset_now_driver_api = {
    .binding_pressed = on_keymap_binding_pressed,
    .binding_released = on_keymap_binding_released,
    .locality = BEHAVIOR_LOCALITY_GLOBAL,
#if IS_ENABLED(CONFIG_ZMK_BEHAVIOR_METADATA)
    .get_parameter_metadata = zmk_behavior_get_empty_param_metadata,
#endif
};

#define RESET_NOW_INST(n)                                                                          \
    static struct behavior_reset_now_data data_##n = {};                                           \
    static const struct behavior_reset_now_config config_##n = {                                   \
        .hold_time_ms = DT_INST_PROP_OR(n, hold_time_ms, 500),                                     \
    };                                                                                             \
    BEHAVIOR_DT_INST_DEFINE(n, NULL, NULL, &data_##n, &config_##n, POST_KERNEL,                    \
                            CONFIG_KERNEL_INIT_PRIORITY_DEFAULT,                                   \
                            &behavior_reset_now_driver_api);

DT_INST_FOREACH_STATUS_OKAY(RESET_NOW_INST)
