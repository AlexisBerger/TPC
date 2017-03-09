#include<stdio.h>
#include<stdlib.h>
#include<SDL\SDL.h>

void pause();
SDL_Surface** degrader(const SDL_Surface* ecran);
void freeTabSurface(SDL_Surface** surface, int taille);

int main() {

	SDL_Surface* ecran = NULL;

	SDL_Surface** degrad = NULL;


	if (SDL_Init(SDL_INIT_VIDEO) == -1) {
		fprintf(stderr, "Init failed : %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}

	ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	if (ecran == NULL) {
		fprintf(stderr, "Init video failed : %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}
	SDL_WM_SetCaption("Ma grosse fenetre", NULL);


	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));



	degrad = degrader(ecran);

	SDL_Flip(ecran);

	pause();

	freeTabSurface(degrad, 256);
	

	SDL_Quit();

	return EXIT_SUCCESS;
}

void pause() {

	SDL_Event event;
	int continuer = 1;

	while (continuer)
	{
		SDL_WaitEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			continuer = 0;
			break;
		}
	}
}

SDL_Surface** degrader(const SDL_Surface* ecran) {
	
	SDL_Rect pos;
	SDL_Surface** rect = malloc(256*sizeof(SDL_Surface*));

	pos.x = 0;
	pos.y = 0;
	for (int i = 0; i < 256; i++)
	{
		rect[i] = SDL_CreateRGBSurface(SDL_HWSURFACE, 800, 1, 32, 0, 0, 0, 0);
		SDL_FillRect(rect[i], NULL, SDL_MapRGB(ecran->format, i, i, i));
		
		SDL_BlitSurface(rect[i], NULL, ecran, &pos);
		pos.y++;
	}
	return rect;

}

void freeTabSurface(SDL_Surface** surface, int taille) {
	for (int i = 0; i < taille; i++)
	{
		SDL_FreeSurface(surface[i]);
	}
}