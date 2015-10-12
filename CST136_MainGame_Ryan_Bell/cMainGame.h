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
#include "cKeyboard.h""

using std::string;

class cMainGame
{

public:
/******************************************************************************************
*	Purpose: Construct game window and initialize members
*
*	Entry: MainGame object is instantiated
*
*	Exit: Each data member is initialized to passed data value
*
******************************************************************************************/
	cMainGame(SDL_Window*, SDL_Surface*, SDL_Surface*, string);

/******************************************************************************************
*	Purpose: Default constructor if an object is instantiated to null parameters
*
*	Entry: MainGame object is instantiated
*
*	Exit: Each data member is initialized to null data value
*
******************************************************************************************/
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
*	Purpose: Loads BMP onto image surface
*
*	Entry: member function is called for object
*
*	Exit: image is loaded in image load surface, and checked for success.
*
******************************************************************************************/
	bool loadMedia();		

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
	SDL_Window* GetgWindow();				//Get Objects's member window

/******************************************************************************************
*	Purpose: Control Game loop
*
*	Entry: Member function is called for mainGame object
*
*	Exit: Keeps game running until enters Quit
*
******************************************************************************************/
	void GameLoop();						

	SDL_Window* gWindow;					//The window we'll be rendering to
	SDL_Surface* gScreenSurface;			//The surface contained by the window
	SDL_Surface* loadedImg;					//The image we will load and show on the screen

private:
	SDL_Window* m_gWindow;					//Member Window
	SDL_Surface* m_gScreenSurface;			//Member Screen Surface
	SDL_Surface* m_loadedImg;				//Member Image
	string m_imgName;						//Command Line Argument 

	SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

/******************************************************************************************
*	Purpose: __________________________________________
*
*	Entry: ____________________________________________
*
*	Exit: _____________________________________________
*
******************************************************************************************/
	SDL_Surface* loadSurface(string imgPath);
};

#endif

