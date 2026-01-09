paint: paint.c
	gcc -Wall -Wextra -g paint.c -o paint `sdl2-config --cflags --libs` 

clean:
	rm -rf paint
