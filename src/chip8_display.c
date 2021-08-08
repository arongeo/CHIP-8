#include "chip8_display.h"
#include <assert.h>

static void chip8_display_in_bounds(int x, int y) {
	assert(x <= CHIP8_DISPLAY_WIDTH && x >= 0 && y <= CHIP8_DISPLAY_HEIGHT && y >= 0);
}

void chip8_display_set_pixel(struct chip8_display* display, int x, int y, bool val) {
	chip8_display_in_bounds(x, y);
	display->pixels[y][x] = val;
}

bool chip8_display_pixel_status(struct chip8_display* display, int x, int y) {
	chip8_display_in_bounds(x, y);
	return display->pixels[y][x];
}
