#include "chip8_memory.h"
#include <assert.h>

static void chip8_is_in_memory(int index) {
	assert(index >= 0 && index < CHIP8_MEMORY_SIZE);
}

void chip8_memory_set(struct chip8_memory* memory, int index, unsigned char val) {
	chip8_is_in_memory(index);
	memory->memory[index] = val;
}

unsigned char chip8_memory_get(struct chip8_memory* memory, int index) {
	chip8_is_in_memory(index);
	return memory->memory[index];
}
