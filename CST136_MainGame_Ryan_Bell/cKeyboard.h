#ifndef cKEYBOARD_H
#define cKEYBOARD_H

//Key press surfaces constants
enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

class cKeyboard
{

public:
	cKeyboard();
	~cKeyboard();

	SDL_Surface* InterpretInput(SDL_Event sdlEvents,
								  SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL]);
private:

};
#endif
