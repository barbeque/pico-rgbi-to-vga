
// ****************************************************************************
//
//                                 Main code
//
// ****************************************************************************

#ifndef _MAIN_H
#define _MAIN_H

// Input RGBI pins
#define PIN_INPUT_RED       5
#define PIN_INPUT_GREEN     4
#define PIN_INPUT_BLUE      3
#define PIN_INPUT_INTENS    0
#define PIN_INPUT_HSYNC     2
#define PIN_INPUT_VSYNC     1

#define INPUT_FIRST_PIN     0
#define INPUT_PIN_COUNT     6

// Output screen resolution
#define WIDTH	320	// screen width
#define HEIGHT	200	// screen height
#define WIDTHBYTE WIDTH	// bytes per line

// Draw box
extern u8 Box[WIDTHBYTE*HEIGHT] __attribute__ ((aligned(4)));

#endif // _MAIN_H
