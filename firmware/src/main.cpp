
// ****************************************************************************
//
//                                 Main code
//
// ****************************************************************************

#include "include.h"

// Draw box
u8 Box[WIDTHBYTE*HEIGHT] __attribute__ ((aligned(4)));

void SketchyDraw() {
	u8* dest = &Box[0];
	int red = 0;
	int green = 0;
	int blue = 0;
	// Just a demo program to see if I can figure out
	// how to draw to a frame buffer

	for(int y = HEIGHT - 1; y >= 0; --y) {
		for(int x = 0; x < WIDTH; ++x) {
			if(y < 5 || y > HEIGHT - 5 || x < 5 || x > WIDTH - 5) {
				red = green = blue = 255;
			}
			else {
				red = 0;
				green = 0;
				blue = 0;
			}

			*dest++ = (u8)((red & 0xe0) | ((green & 0xe0) >> 3) | (blue >> 6));
		}
	}
}

int main()
{
	// Set up input PIO.

	// Input basic loop:
	//	start capturing at vsync (+timing?)
	//	start new line at hsync (+timing?)
	//	loop at some fixed frequency to capture four pins (IBGR) 320 times
	//	transfer those pins into the video buffer somehow?

	// I have 66ms per line, so that means I need to sample one pixel every 0.2ish ms or 0.005MHz?

	// Might need to set sm_config_set_clkdiv to slow the input SM clock relative to the VGA one

	// It may have been a mistake to put intensity before HV RGB as PIO `in` captures a block at a time.
	// Might want to bodge the hardware so it goes I, B, G, R, V, H even if it's more annoying to
	// route - that way we can just grip and rip the first four pins

	// run VGA core
	// initialize videomode

	// RES_EGA - 528x400 (really 512x400, it seems)
	// RES_VGA - 640x480
	// RES_CGA - 320x200

	// TODO: 4-bit colour
	// TODO: palette configuration

	Video(DEV_VGA, RES_CGA, FORM_8BIT, Box);

	SketchyDraw();

	// main loop
	while (true)
	{
		// Reformat and copy from the DMA recipient raw data buffer
		// (it chunks out 32-bits at a time)
	}
}
