
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
	// run VGA core
//	multicore_launch_core1(VgaCore);

	// initialize videomode

	// RES_EGA - 528x400 (really 512x400, it seems)
	// RES_VGA - 640x480
	// RES_CGA - 320x200

	Video(DEV_VGA, RES_CGA, FORM_8BIT, Box);

	SketchyDraw();

	// main loop
	while (true)
	{


	}
}
