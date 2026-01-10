#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define WIDTH 640
#define HEIGHT 480
#define TARGET_FPS 244
#define WHITE 0xffffff
#define BLACK 0x000000

int main() {

	bool done = false;

	SDL_Init(SDL_INIT_VIDEO);

	// Create the window
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

	// Fetch the window surface and paint white
	SDL_Surface *surface = SDL_GetWindowSurface(window);
	SDL_FillRect(surface, NULL, WHITE);
	SDL_UpdateWindowSurface(window);

	float fps_enforcer = 1.0 / TARGET_FPS * 1000; // How long the program should delay before drawing the next frame (ms)
	while (!done) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch(event.type) {

				case SDL_QUIT:
					done = true;
					break;
				case SDL_MOUSEMOTION:
					SDL_Rect curPos = { event.motion.x, event.motion.y, 1, 1 };
					SDL_FillRect(surface, &curPos, BLACK);
			}
		}
		SDL_UpdateWindowSurface(window);
		SDL_Delay(fps_enforcer);
	}

	return 0;
}
