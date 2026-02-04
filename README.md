# ZMK Eyeslash Corne mit XIAO BLE Dongle

Dies ist meine persönliche [zmk](https://github.com/zmkfirmware/zmk) Konfiguration für meine
[eyeslash_corne](https://github.com/tokyo2006/zmk-corne-dongle) Tastatur. Die Firmware ist entwickelt für die folgende Hardware:

- **Tastatur**: Eyeslash Corne 34-Key Split
- **Dongle**: Seeed XIAO BLE nRF52840
- **Peripherals**: Nice!nano v2 + Nice!view custom (linke/rechte Tastatur)
- **Features**: EC11 Encoder, 5-Wege-Switch, RGB Underglow, SH1106 OLED Display

> Dies ist ein Dongle-Setup mit ZMK Studio Support. Die linke und rechte Tastatur agieren beide als Peripheriegeräte, während der Seed XIAO als Hauptcontroller fungiert. Dies erhöht die Batterielaufzeit der linken Tastatur im Vergleich zur Verwendung als Haupt- und linkes Peripheriegerät.

## Hardware Features

### Eyeslash Corne Besonderheiten
- **34-Key Layout**: Erweitertes Corne-Design mit 5-Wege-Switch im Daumencluster
- **EC11 Encoder**: Multi-funktionaler Drehgeber links
- **RGB Underglow**: WS2812 LED-Stripe mit 7 LEDs
- **SH1106 OLED**: 129×64 Display auf dem Dongle
- **Advanced Mouse Control**: Hohe Sensibilität (1200px Bewegung, 20px Scroll)
- **Tap-Dance**: Shift/Caps Lock Kombination

### Build-Ziele

Für den Dongle (XIAO):
- `xiao_eyeslash_dongle_oled.uf2` - Mit OLED Display Support
- `xiao_eyeslash_dongle.uf2` - Ohne OLED Display
- `xiao_reset_settings.uf2` - Zumindest Einstellungen zurücksetzen

Für die Tastatur (Eyeslash Corne):
- `nano_eyeslash_left.uf2` - Linke Hälfte
- `nano_eyeslash_right.uf2` - Rechte Hälfte
- `nano_reset_settings.uf2` - Zumindest Einstellungen zurücksetzen

## Keymap Layers

### Layer 0 (QWERTY)
Standard-Treibschicht mit Pfeiltasten im Daumencluster, Lautstärkeregelung über Encoder und Tap-Dance für Shift/Caps Lock.

### Layer 1 (Number/Mouse)
Ziffern, Funktionstasten, Maussteuerung mit erweiterter Empfindlichkeit und RGB-Kontrollen. 5-Wege-Switch für Navigation.

### Layer 2 (Symbol)
Symbole, Mausknöpfe, Output-Switching (USB/BLE) und erweiterte Mausfunktionen.

### Layer 3 (Function)
F-Tasten, Systemsteuerung, Reset-Funktionen und Studio-Unlock für Debugging.

## Features im Detail

### Encoder-Funktionen
- **Layer 0**: Lautstärke auf/ab
- **Layer 1**: RGB Helligkeit auf/ab
- **Layer 2**: Scroll auf/ab

### 5-Wege-Switch
- **Layer 1**: Navigation (Hoch/Runter/Links/Rechts + Press)
- **Layer 2**: Maus-Funktionen

### RGB Steuerung
- HSV-Farbsystem mit Startfarbe Grün (160°)
- Maximale Helligkeit 90%
- Auto-Off bei Inaktivität und USB-Verbindung

### Mouse Control
- Bewegungsempfindlichkeit: 1200px (Standard: 600px)
- Scroll-Empfindlichkeit: 20px (Standard: 10px)
- XY-Scaling Processor für präzise Kontrolle

## Installation

### Dongle Flashing (XIAO)
1. XIAO Dongle mit Computer verbinden
2. Doppelklick auf kleine Taste für Bootloader-Modus
3. `xiao_reset_settings.uf2` kopieren (Optional, empfohlen für sauberen Start)
4. Nach Fehlermeldung abziehen und wieder anschließen
5. Erneut Doppelklick für Bootloader-Modus
6. `xiao_eyeslash_dongle_oled.uf2` (oder `xiao_eyeslash_dongle.uf2`) kopieren
7. Nach Fehlermeldung abziehen

### Tastatur Flashing (Nice!nano)
1. Linke Tastatur verbinden (nicht einschalten)
2. Seitentaste doppelklicken für Bootloader-Modus
3. `nano_reset_settings.uf2` kopieren
4. Nach Fehlermeldung abziehen und wieder anschließen
5. Erneut seitentaste doppelklicken
6. `nano_eyeslash_left.uf2` kopieren (wichtig: linke Firmware!)
7. Schritte 1-6 für rechte Tastatur mit `nano_eyeslash_right.uf2` wiederholen

### Abschluss
8. XIAO Dongle wieder mit Computer verbinden
9. Beide Tastaturhälften einschalten
10. Fertig!

## Abhängigkeiten

- ZMK v0.3.0
- hammerbeam-slideshow (GPeye)
- prospector-zmk-module (tokyo2006)  
- zmk-dongle-display (englmaxi)
- nice-view-gem v0.3.0 (M165437)

## Build

Das Projekt verwendet GitHub Actions für automatisierte Builds. Die `.github/workflows/build.yml` Datei konfiguriert den Build-Prozess für alle definierten Ziele.

> Die `*_reset_settings.uf2` Dateien werden verwendet, um persistente Einstellungen wie Default-Layer, BLE-Pairings und andere gespeicherte Daten zu löschen, die nach wiederholtem Flashen neuer Firmware verbleiben können.# zmk
