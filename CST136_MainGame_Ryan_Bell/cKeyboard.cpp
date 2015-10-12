#include <SDL.h>
#include "cKeyboard.h"

cKeyboard::cKeyboard()
{
}

cKeyboard::~cKeyboard()
{
}

SDL_Surface* cKeyboard::InterpretInput(SDL_Event sdlEvents, SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL])
{
	SDL_Surface* surfaceToReturn = nullptr;
	switch (sdlEvents.key.keysym.sym)
	{
	case SDLK_UP:
		surfaceToReturn = gKeyPressSurfaces[KEY_PRESS_SURFACE_UP];
		break;

	case SDLK_DOWN:
		surfaceToReturn = gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
		break;

	case SDLK_LEFT:
		surfaceToReturn = gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
		break;

	case SDLK_RIGHT:
		surfaceToReturn = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
		break;

	default:
		surfaceToReturn = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
		break;
	}
	return surfaceToReturn;
}