#ifndef CHIP8_REGISTERS_H
#define CHIP8_REGISTERS_H

#include "config.h"

struct chip8_registers {
	unsigned char V[CHIP8_NUM_OF_DATA_REGISTERS];
	unsigned short I;
	unsigned char DT;
	unsigned char ST;
};

#endif // CHIP8_REGISTERS_H
