#ifndef CHIP8_DISPLAY
#define CHIP8_DISPLAY

#include <stdbool.h>
#include "config.h"

struct chip8_display {
	bool pixels[CHIP8_DISPLAY_HEIGHT][CHIP8_DISPLAY_WIDTH];
};

void chip8_display_set_pixel(struct chip8_display* display, int x, int y, bool val);

bool chip8_display_pixel_status(struct chip8_display* display, int x, int y);

#endif // CHIP8_DISPLAY
