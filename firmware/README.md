# Firmware for Pico RGBI to VGA

## Build instructions
 * Install `cmake` and the Raspberry Pi Pico SDK and all related tools
    * Mac: https://www.robertthasjohn.com/post/how-to-set-up-the-raspberry-pi-pico-for-development-on-macos
 * `cmake .` will generate a Makefile
 * `make` will use that Makefile to generate `rgbi.uf2`, if all went well
