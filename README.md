# Pico RGBI to VGA
_(Name subject to change in future)_

## Current Status
Not working

TODO:
 - [ ] Hook up logic analyzer example to capture input video
 - [ ] Buffer input video into output
 - [ ] Test 4-bit colour output mode
 - [ ] Create multiple palettes and palette switch handler

## The Problem
Several old computers, such as the NEC PC-6001mkII, use an "RGB+I" output at TTL level (+5V.) It is becoming difficult to locate monitors which support this output. Modern displays, and I use the term loosely because the VGA port has virtually become extinct as I am writing this in 2022, use analogue RGB to convey a greater range of colours.

For some computers, such as the NEC PC-8801mkII and Sanyo MBC-555, there are only three digital pins: red, green, and blue. Combined, this makes 8 colours (2<sup>3</sup> = 8.) Later computers added an "intensity" pin, which essentially works as the equivalent of a Shift key for these colours, and expands the available colours to 15 (2<sup>4</sup> = 16, but "bright black" is still just black.) For instance, the PC-6001mkII will signal "bright red" as by setting the "red" and "intensity" pins to 5V and everything else to 0V. "White" would set all four pins to 5V.

## Current Status
The board is still *IN DEVELOPMENT*. Please do not use it unless you are willing to test with your machines, potentially write some code, and submit bug reports and feedback. There may be a risk of damage to your hardware or to the Pico if things go wrong.

## Compatibility
Here is a brief list of computers that are known to work with such a model, although they may require a custom cable made for this board:

 | Computer | Adapter configuration | Notes |
 |----------|-----------------------|-------|
 | NEC PC-6001mkII | Intensity: pin 3 | Not tested |
 | NEC PC-6001mkIISR | Intensity: pin 3 | Not tested |
 | NEC PC-6601 | Intensity: pin 3 | Not tested |
 | NEC PC-6601SR | Intensity: pin 3 | Not tested |
 | NEC PC-9801UV | Disable intensity | Not tested |
 | NEC PC-8001 | Disable intensity | Not tested |
 | NEC PC-8801mkII | Intensity *must* be disabled or it will pass +12V through and *damage the Pico*! | Not tested |
 | IBM CGA | Custom cable required | Not tested |
 | Sanyo MBC-550/MBC-555 | Disable intensity | Not tested |
 | Commodore C128 | Custom cable required | Not tested |
 | Fujitsu FM-7/FM-New7 | Disable intensity | Not tested; intensity may not be possible |
 | Fujitsu FM-77AV2 | Custom cable required | Not tested; intensity may not be possible |

Please submit a pull request if you have tested another computer, know of one to add to the list, or can contribute custom cable designs.

## Build Instructions
### Hardware
TODO

### Software
Refer to [the `firmware` directory](firmware/)'s README for build instructions.
