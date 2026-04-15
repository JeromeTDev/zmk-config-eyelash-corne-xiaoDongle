# ZMK Eyeslash Corne with XIAO BLE Dongle

![corne](assets/corne.jpeg)

![keymap](keymap-drawer/eyeslash_corne.svg)

**[English](#english) | [Deutsch](#deutsch)**
  
---

## English

This is my personal [zmk](https://githu.com/zmkfirmware/zmk) configuration for my
[eyeslash_corne](https://de.aliexpress.com/item/1005008551330418.html?spm=a2g0o.order_list.order_list_main.5.21ef5c5fdIQpG1&gatewayAdapt=glo2deu) keyboard. The firmware is developed for the following hardware:

- **Keyboard**: Eyeslash Corne
- **Dongle**: Seeed XIAO BLE nRF52840


> This is a dongle setup with ZMK studio support. The left and right keyboard both act as peripherals while the Seed XIAO functions as the main controller. This increases the battery life of the left keyboard compared to using it as both main and left peripheral. Furthermore you can unlock your encrypted harddrive before boot.

#### Build Targets

For Dongle (XIAO):
- `xiao_eyeslash_dongle_oled.uf2` - With OLED display support
- `xiao_eyeslash_dongle.uf2` - Without OLED display
- `xiao_reset_settings.uf2` - Reset persistent settings

For Keyboard (Eyeslash Corne):
- `nano_eyeslash_left.uf2` - Left half
- `nano_eyeslash_right.uf2` - Right half
- `nano_reset_settings.uf2` - Reset persistent settings

 #### Installation

**Dongle Flashing (XIAO)**
1. Connect XIAO dongle to computer
2. Double-press small button for bootloader mode
3. Copy `xiao_reset_settings.uf2` (Optional, recommended for clean start)
4. After error appears, unplug and reconnect
5. Double-press button again for bootloader mode
6. Copy `xiao_eyeslash_dongle_oled.uf2` (or `xiao_eyeslash_dongle.uf2`)
7. After error appears, unplug

**Keyboard Flashing (Nice!nano)**
1. Connect left keyboard (don't turn on)
2. Double-press side button for bootloader mode
3. Copy `nano_reset_settings.uf2`
4. After error appears, unplug and reconnect
5. Double-press side button again
6. Copy `nano_eyeslash_left.uf2` (important: left firmware!)
7. Repeat steps 1-6 for right keyboard with `nano_eyeslash_right.uf2`

**Completion**
8. Connect XIAO dongle back to computer
9. Turn on both keyboard halves
10. Done!

#### Keymap Features

This configuration is optimized for **German developers** using a **US-ANSI base layout** (QWERTY).

* **Logic:** US-Layout for coding, with easy access to German specials.
* **Umlauts (Raise Layer):** - Dedicated keys for `ä`, `ö`, `ü`, and `ß` using `Right Alt` (AltGr) combinations. 
    - Positioned for minimal finger travel on the left half.
* **Numpad (Lower Layer):** - **Homing-Centric:** The number `5` is placed on the `J` key (right index finger), allowing for blind typing using the physical homing bar.
    - **Integrated Operators:** Arithmetic operators (`/`, `*`, `-`, `+`, `=`) are aligned in a vertical column on the right edge for quick calculations.
    - **Thumb-Zero:** The `0` is mapped to the right thumb for a natural "calculator-style" workflow.
* **Ergonomics:**
    - Shift/Caps Lock Tap Dance on the left Shift.
    - Backspace/Delete Mod-Morph (Backspace on tap, Delete on Shift+tap).
    - Mouse movement and scrolling integrated into layers.

#### Dependencies

- ZMK v0.3.0
- hammerbeam-slideshow (GPeye)
- prospector-zmk-module (tokyo2006)  
- zmk-dongle-display (englmaxi)
- nice-view-gem v0.3.0 (M165437)

#### Build

The project uses GitHub Actions for automated builds. The `.github/workflows/build.yml` file configures the build process for all defined targets.

> The `*_reset_settings.uf2` files are used to clear persistent settings like default layers, BLE pairings, and other saved data that may remain after repeatedly flashing new firmware.

---

## Deutsch
Dies ist meine persönliche [ZMK](https://github.com/zmkfirmware/zmk) Konfiguration für die **Eyeslash Corne** Tastatur.

- **Tastatur**: Eyeslash Corne (Split)
- **Dongle**: Seeed XIAO BLE nRF52840
- **Besonderheit**: Dongle-Setup mit ZMK Studio Support. Beide Tastaturhälften agieren als Peripheriegeräte, während der XIAO als zentraler Controller dient. Dies schont den Akku der linken Hälfte und ermöglicht die Passworteingabe (z.B. für Festplattenverschlüsselung) bereits vor dem Betriebssystem-Boot.

#### Besonderheiten der Tastaturbelegung

Die Keymap ist für **Software-Entwickler** optimiert, die ein **US-ANSI (QWERTY)** Basis-Layout bevorzugen, aber nicht auf deutsche Sonderzeichen verzichten wollen.

* **Umlaute (Raise Layer):** Direkter Zugriff auf `ä`, `ö`, `ü` und `ß` über Tastenkombinationen mit `Right Alt` (AltGr) auf der linken Tastaturhälfte.
* **Ergonomisches Numpad (Lower Layer):**
    * **Zentrierte Ausrichtung:** Die Zahl **5** liegt genau auf der Taste **J** (rechter Zeigefinger). Da dies die Orientierungstaste mit der fühlbaren Markierung ist, lässt sich das Numpad blind bedienen.
    * **Daumen-Null:** Die `0` liegt auf der rechten Daumentaste, was einen natürlichen "Taschenrechner-Workflow" ermöglicht.
* **Komfort-Funktionen:**
    * **Tap-Dance:** Die linke Shift-Taste aktiviert bei doppeltem Tippen den `Caps Lock`.
    * **Mod-Morph:** Die Backspace-Taste wird bei gehaltener Shift-Taste automatisch zur `Entfernen`-Taste (Delete).
    * **Maus-Steuerung:** Cursor-Bewegungen und Scrolling sind direkt in die Layer integriert.

#### Installation

1.  **Dongle flashen (XIAO):** XIAO in den Bootloader-Modus versetzen (2x Reset drücken) und `xiao_eyeslash_dongle_oled.uf2` auf das Laufwerk kopieren.
2.  **Hälften flashen (Nice!nano):** Jeweils die linke und rechte Hälfte mit der entsprechenden Firmware (`nano_eyeslash_left.uf2` bzw. `right`) bespielen.
3.  **Verbinden:** Dongle einstecken, Hälften einschalten – fertig.
