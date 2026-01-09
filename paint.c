#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define WIDTH 640
#define HEIGHT 480

int main() {

	bool done = false;

	SDL_Init(SDL_INIT_VIDEO);

	// Create an application window
	SDL_Window *window = SDL_CreateWindow(
		"Paint-C",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WIDTH,
		HEIGHT,
		0
	);
	
	// Check for successful creation of the window
	if (window == NULL) {
		fprintf(stderr, "Failed to create SDL window. Exiting");
		return 1;
	}

	while (!done) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				done = true;
			}
		}
	}

	return 0;
}
