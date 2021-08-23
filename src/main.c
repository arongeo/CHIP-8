#define SDL_MAIN_HANDLED

#include <stdio.h>
#include <SDL2/SDL.h>
#include "chip8.h"
#include <stdbool.h>

const char keyboard_map[CHIP8_TOTAL_KEYS] = {
	SDLK_0, SDLK_1, SDLK_2, SDLK_3, SDLK_4, SDLK_5,
	SDLK_6, SDLK_7, SDLK_8, SDLK_9, SDLK_a, SDLK_b,
	SDLK_c, SDLK_d, SDLK_e, SDLK_f
};

int main(int argc, char** argv) {
	struct chip8 chip8;
	
	chip8_init(&chip8);
	SDL_Init(SDL_INIT_EVERYTHING);

	chip8_display_set_pixel(&chip8.display, 0, 0, true);

	SDL_Window* window = SDL_CreateWindow(
			EMULATOR_WINDOW_TITLE,
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			CHIP8_DISPLAY_WIDTH*CHIP8_WINDOW_MULTIPLIER,
			CHIP8_DISPLAY_HEIGHT*CHIP8_WINDOW_MULTIPLIER,
			SDL_WINDOW_SHOWN
		);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_TEXTUREACCESS_TARGET);
	int quit = 0;
	while (quit == 0) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for (int x = 0; x<CHIP8_DISPLAY_WIDTH; x++) {
			for (int y = 0; y<CHIP8_DISPLAY_HEIGHT; y++) {			
				if (chip8_display_pixel_status(&chip8.display, x, y) == true) {
					SDL_Rect r;
					r.x = x * CHIP8_WINDOW_MULTIPLIER;
					r.y = y * CHIP8_WINDOW_MULTIPLIER;
					r.w = CHIP8_WINDOW_MULTIPLIER;
					r.h = CHIP8_WINDOW_MULTIPLIER;
					SDL_RenderFillRect(renderer, &r);
				}
			}
		}
		SDL_RenderPresent(renderer);
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT:
					quit = 1;
				break;

				case SDL_KEYDOWN: {
					char key = event.key.keysym.sym;
					int virtual_key = chip8_key_map(keyboard_map, key);
					if (virtual_key != -1) {
						chip8_key_down(&chip8.keyboard, virtual_key);
					}	
				}	
				break;
				
				case SDL_KEYUP: {
					char key = event.key.keysym.sym;
					int virtual_key = chip8_key_map(keyboard_map, key);
					if (virtual_key != -1) {
						chip8_key_up(&chip8.keyboard, virtual_key);
					}
				}	
				break;
			};
		}
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
