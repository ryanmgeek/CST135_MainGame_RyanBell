//cMainGame.h
/******************************************************************************************
* Class: cMainGame
*
* Constructors:
* -------------
*	cTime()
*		Window, Screen Surface, and loaded image surface are initialized
*		and base member's are initialized.
* Mutators:
* ---------
*	No Mutator Implemented
* --------
*	bool init()
*		Initializes SDL video and creates window ensuring that the data is valid.
*	bool loadMedia()
*		Loads a BMP image to the surface, ensuring that it was successful in doing so.
*	void close()
*		Deallocates surface, destroys window, quits SDL, frees any allocated memory
*		and nulls pointers.
*	SDL_Surface* GetLoadedImg()
*		Returns object's current Loaded Image surface member.
*	SDL_Surface* GetgScreenSurface()
*		Returns object's current Screen Surface member.
*	SDL_Window* GetgWindow()
*		Return object's current window member.
*
*
******************************************************************************************/

#ifndef CMAINGAME_H
#define CMAINGAME_H

#include <SDL.h>
#include <string>
#include "cKeyboard.h"
#include "cSurfaceManager.h"

using std::string;

class cMainGame
{

public:

	cMainGame();
/******************************************************************************************
*	Purpose: Destroy mainGame object
*
*	Entry: Object goes out of scope
*
*	Exit: Requested memory is freed and pointers set back to null
*
******************************************************************************************/
	~cMainGame();			

/******************************************************************************************
*	Purpose: Initialize Game Window
*
*	Entry: function is called for a cMainGame object
*
*	Exit: SDL is initialized and a default gWindow is created for the object. The windows
*		  surface is stored into the data member of gScreenSurface for later use.
*		  Initialization is check for an thrown exceptions.
*
******************************************************************************************/
	bool init();								

/******************************************************************************************
*	Purpose: Deallocate resources and free memory
*
*	Entry: member is function is called for mainGame object
*
*	Exit: Image surface, window, and SDL are freed from memory and pointer nulled
*
******************************************************************************************/
	void close();							

/******************************************************************************************
*	Purpose: Control Game loop
*
*	Entry: Member function is called for mainGame object
*
*	Exit: Keeps game running until enters Quit
*
******************************************************************************************/
	void GameLoop(cSurfaceManager windowObj);

private:
	
};

#endif

