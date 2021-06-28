#include "chip8_keyboard.h"
#include <assert.h>

static void chip8_key_in_bounds(int key) {
	assert(key < CHIP8_TOTAL_KEYS && 0 <= key);
}

int chip8_key_map(const char* map, char key) {
	for (int i = 0; i<CHIP8_TOTAL_KEYS; i++) {
		if (map[i] == key) {
			return i;
		}
	}
	return -1;
}

void chip8_key_down(struct chip8_keyboard* keyboard, int key) {
	chip8_key_in_bounds(key);
	keyboard->keyboard[key] = true;
}

void chip8_key_up(struct chip8_keyboard* keyboard, int key) {
	chip8_key_in_bounds(key);
	keyboard->keyboard[key] = false;
}

bool chip8_key_status(struct chip8_keyboard* keyboard, int key) {
	chip8_key_in_bounds(key);
	return keyboard->keyboard[key];
}
