#include <stdio.h>
#include <SDL2/SDL.h>
#include "chip8.h"

int main(int argc, char** argv) {
	struct chip8 chip8;
	chip8.registers.SP = 0;

	chip8_stack_push(&chip8, 32);
	chip8_stack_push(&chip8, 0xaa);
	printf("%x\n", chip8_stack_pop(&chip8));
	printf("%x\n", chip8_stack_pop(&chip8));

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow(
			EMULATOR_WINDOW_TITLE,
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			CHIP8_WIDTH*CHIP8_WINDOW_MULTIPLIER,
			CHIP8_HEIGHT*CHIP8_WINDOW_MULTIPLIER,
			SDL_WINDOW_SHOWN
		);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_TEXTUREACCESS_TARGET);
	int quit = 0;
	while (quit == 0) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		SDL_Rect r;
		r.x = 0;
		r.y = 0;
		r.w = 40;
		r.h = 40;
		SDL_RenderFillRect(renderer, &r);
		SDL_RenderPresent(renderer);
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit = 1;
			}
		}
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
