#ifndef CHIP8_KEYBOARD_H
#define CHIP8_KEYBOARD_H

#include <stdbool.h>
#include "config.h"

struct chip8_keyboard {
	bool keyboard[CHIP8_TOTAL_KEYS];
};

int chip8_key_map(const char* map, char key);
void chip8_key_down(struct chip8_keyboard* keyboard, int key);
void chip8_key_up(struct chip8_keyboard* keyboard, int key);
bool chip8_key_status(struct chip8_keyboard* keyboard, int key); // If true key is down, if false key is up.

#endif // CHIP8_KEYBOARD_H
