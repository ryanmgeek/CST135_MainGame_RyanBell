#ifndef CSURFACEMANGER_H
#define CSURFACEMANGER_H

#include <SDL.h>
#include <string>
#include "cKeyboard.h"

using std::string;

class cSurfaceManager
{

public:
	SDL_Window* gWindow;					//The window we'll be rendering to
	SDL_Surface* gScreenSurface;			//The surface contained by the window
	SDL_Surface* loadedImg;					//The image we will load and show on the screen

/******************************************************************************************
*	Purpose: Construct game window and initialize members
*
*	Entry: MainGame object is instantiated
*
*	Exit: Each data member is initialized to passed data value
*
******************************************************************************************/
	cSurfaceManager(SDL_Window*, SDL_Surface*, SDL_Surface*, string);

/******************************************************************************************
*	Purpose: Default constructor if an object is instantiated to null parameters
*
*	Entry: MainGame object is instantiated
*
*	Exit: Each data member is initialized to null data value
*
******************************************************************************************/
	cSurfaceManager();

	~cSurfaceManager();

/******************************************************************************************
*	Purpose: Get member Image surface
*
*	Entry: Member function is called for mainGame object
*
*	Exit: returns loadedImg member surface for object
*
******************************************************************************************/
	SDL_Surface* GetLoadedImg();

/******************************************************************************************
*	Purpose: Get member screen Surface
*
*	Entry: Member function is called for mainGame object
*
*	Exit: Returns screen surface member for object
*
******************************************************************************************/
	SDL_Surface* GetgScreenSurface();

/******************************************************************************************
*	Purpose: Get member window
*
*	Entry: Member function is called for mainGame object
*
*	Exit: Returns window member for object
*
******************************************************************************************/
	SDL_Window* GetgWindow();

/******************************************************************************************
*	Purpose: Loads BMP onto image surface
*
*	Entry: member function is called for object
*
*	Exit: image is loaded in image load surface, and checked for success.
*
******************************************************************************************/
	bool loadMedia();

/******************************************************************************************
*	Purpose: Frees Any Surface/ Windows instantiated 
*
*	Entry: Function is called for Window object
*
*	Exit: Surfaces are freed and nulled
*
******************************************************************************************/
	void FreeSurfaces();

/******************************************************************************************
*	Purpose: Updates Window object
*
*	Entry: Event handler gets a key down and surface needs to be updated based on input
*
*	Exit: The window object is updated to the corresponding image of their key-press
*
******************************************************************************************/
	void SetWindow(SDL_Event sdlEvents);

private:
	SDL_Surface* m_gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
	SDL_Surface* m_loadedImg;				//Member Image
	SDL_Window* m_gWindow;					//Member Window
	SDL_Surface* m_gScreenSurface;			//Member Screen Surface
	string m_imgName;						//Command Line Argument

/******************************************************************************************
*	Purpose: Loads corresponding image onto surface
*
*	Entry: load Surface is called for a bmp image
*
*	Exit: bmp image manging the passed string is opened and loaded into the array
*
******************************************************************************************/
	SDL_Surface* loadSurface(string imgPath);

};

#endif

