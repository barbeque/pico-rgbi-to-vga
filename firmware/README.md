# Firmware for Pico RGBI to VGA

## Build instructions
 * Install `cmake` and the Raspberry Pi Pico SDK and all related tools
    * Mac: https://www.robertthasjohn.com/post/how-to-set-up-the-raspberry-pi-pico-for-development-on-macos
 * Clone [PicoVGA source tree](https://github.com/Panda381/PicoVGA) and put it parallel to the `pico-rgbi-to-vga` checkout as `PicoVGA`, or set `PICOVGA_PATH` environment variable if you want to put it somewhere else
 * `cmake .` will generate a Makefile
 * `make` will use that Makefile to generate `rgbi.uf2`, if all went well
