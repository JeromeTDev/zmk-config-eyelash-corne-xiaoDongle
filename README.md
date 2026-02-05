# ZMK Eyeslash Corne with XIAO BLE Dongle

![corne](assets/corne.jpeg)

![keymap](keymap-drawer/eyeslash_corne.svg)

**[English](#english) | [Deutsch](#deutsch)**
  
---

## English

This is my personal [zmk](https://github.com/zmkfirmware/zmk) configuration for my
[eyeslash_corne](https://github.com/tokyo2006/zmk-corne-dongle) keyboard. The firmware is developed for the following hardware:

- **Keyboard**: Eyeslash Corne 34-Key Split
- **Dongle**: Seeed XIAO BLE nRF52840
- **Peripherals**: Nice!nano v2 + Nice!view custom (left/right keyboard)
- **Features**: EC11 Encoder, 5-way switch, RGB underglow, SH1106 OLED display

> This is a dongle setup with ZMK studio support. The left and right keyboard both act as peripherals while the Seed XIAO functions as the main controller. This increases the battery life of the left keyboard compared to using it as both main and left peripheral.

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

Dies ist meine persönliche [zmk](https://github.com/zmkfirmware/zmk) Konfiguration für meine
[eyeslash_corne](https://github.com/tokyo2006/zmk-corne-dongle) Tastatur. Die Firmware ist entwickelt für die folgende Hardware:

- **Tastatur**: Eyeslash Corne 34-Key Split
- **Dongle**: Seeed XIAO BLE nRF52840
- **Peripherals**: Nice!nano v2 + Nice!view custom (linke/rechte Tastatur)
- **Features**: EC11 Encoder, 5-Wege-Switch, RGB Underglow, SH1106 OLED Display

> Dies ist ein Dongle-Setup mit ZMK Studio Support. Die linke und rechte Tastatur agieren beide als Peripheriegeräte, während der Seed XIAO als Hauptcontroller fungiert. Dies erhöht die Batterielaufzeit der linken Tastatur im Vergleich zur Verwendung als Haupt- und linkes Peripheriegerät.



#### Build-Ziele

Für den Dongle (XIAO):
- `xiao_eyeslash_dongle_oled.uf2` - Mit OLED Display Support
- `xiao_eyeslash_dongle.uf2` - Ohne OLED Display
- `xiao_reset_settings.uf2` - Einstellungen zurücksetzen

Für die Tastatur (Eyeslash Corne):
- `nano_eyeslash_left.uf2` - Linke Hälfte
- `nano_eyeslash_right.uf2` - Rechte Hälfte
- `nano_reset_settings.uf2` - Einstellungen zurücksetzen

#### Installation

**Dongle Flashing (XIAO)**
1. XIAO Dongle mit Computer verbinden
2. Doppelklick auf kleine Taste für Bootloader-Modus
3. `xiao_reset_settings.uf2` kopieren (Optional, empfohlen für sauberen Start)
4. Nach Fehlermeldung abziehen und wieder anschließen
5. Erneut Doppelklick für Bootloader-Modus
6. `xiao_eyeslash_dongle_oled.uf2` (oder `xiao_eyeslash_dongle.uf2`) kopieren
7. Nach Fehlermeldung abziehen

**Tastatur Flashing (Nice!nano)**
1. Linke Tastatur verbinden (nicht einschalten)
2. Seitentaste doppelklicken für Bootloader-Modus
3. `nano_reset_settings.uf2` kopieren
4. Nach Fehlermeldung abziehen und wieder anschließen
5. Erneut seitentaste doppelklicken
6. `nano_eyeslash_left.uf2` kopieren (wichtig: linke Firmware!)
7. Schritte 1-6 für rechte Tastatur mit `nano_eyeslash_right.uf2` wiederholen

**Abschluss**
8. XIAO Dongle wieder mit Computer verbinden
9. Beide Tastaturhälften einschalten
10. Fertig!

#### Abhängigkeiten

- ZMK v0.3.0
- hammerbeam-slideshow (GPeye)
- prospector-zmk-module (tokyo2006)  
- zmk-dongle-display (englmaxi)
- nice-view-gem v0.3.0 (M165437)

#### Build

Das Projekt verwendet GitHub Actions für automatisierte Builds. Die `.github/workflows/build.yml` Datei konfiguriert den Build-Prozess für alle definierten Ziele.

> Die `*_reset_settings.uf2` Dateien werden verwendet, um persistente Einstellungen wie Default-Layer, BLE-Pairings und andere gespeicherte Daten zu löschen, die nach wiederholtem Flashen neuer Firmware verbleiben können.
