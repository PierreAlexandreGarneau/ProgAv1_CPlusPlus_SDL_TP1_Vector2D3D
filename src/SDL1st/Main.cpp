#include <SDL.h>
#include <stdio.h>

int main(int argc, char* args[])
{
	SDL_Window* window = nullptr;
	SDL_Surface* screen = nullptr;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		window = SDL_CreateWindow("SDL1st", 
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
			768, 432, SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);
		if (window == nullptr)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			screen = SDL_GetWindowSurface(window);

			SDL_FillRect(screen, nullptr, SDL_MapRGB(screen->format, 0x00, 0x00, 0x00));

			SDL_UpdateWindowSurface(window);

			SDL_Delay(2000);
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}