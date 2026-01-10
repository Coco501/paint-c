#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480
#define TARGET_FPS 244
#define WHITE 0xffffff
#define BLACK 0x000000

int distance_from_to(int x_1, int y_1, int x_2, int y_2) {
	return ceil(sqrt(pow(x_2 - x_1, 2) + pow(y_2 - y_1, 2)));
}

// Draws a circle with center x, y and radius r
void draw_circle(SDL_Surface *surface, int x, int y, int r) {
	SDL_Rect rect = { 0, 0, 1, 1 };

	for (int i = x-r; i < x+r; i++) {
		for (int j = y-r; j < y+r; j++) {
			if (distance_from_to(x, y, i, j) <= r) {
				rect.x = i;
				rect.y = j;
				SDL_FillRect(surface, &rect, BLACK);
			}
		}
	}
}

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

	// Fetch the window surface and paint white to start
	SDL_Surface *surface = SDL_GetWindowSurface(window);
	SDL_FillRect(surface, NULL, WHITE);
	SDL_UpdateWindowSurface(window);

	// How long the program should delay before drawing the next frame (ms)
	float fps_enforcer = 1.0 / TARGET_FPS * 1000; 

	while (!done) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch(event.type) {

				case SDL_QUIT:
					done = true;
					break;
				case SDL_MOUSEMOTION:
					draw_circle(surface, event.motion.x, event.motion.y, 3);
			}
		}

		SDL_UpdateWindowSurface(window);
		SDL_Delay(fps_enforcer);
	}

	return 0;
}
