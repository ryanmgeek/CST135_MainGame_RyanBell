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

	cMainGame(SDL_Window*, SDL_Surface*, SDL_Surface*, string);
	//CTOR- creating Window, surface, image, command line argument
	cMainGame();			//Default cTor for instantiated objs with no parameters
	~cMainGame();			//DTOR- Frees memory destroying object

	bool init();							//Initialize new window
	bool loadMedia();						//Load Media to window
	void close();							//Close window and free memory

	SDL_Surface* GetLoadedImg();			//Get object's member img surface
	SDL_Surface* GetgScreenSurface();		//Get object's member screen surface
	SDL_Window* GetgWindow();				//Get Objects's member window

	void GameLoop();						//Loop Game until user enter Quit

	SDL_Window* gWindow;					//The window we'll be rendering to
	SDL_Surface* gScreenSurface;			//The surface contained by the window
	SDL_Surface* loadedImg;					//The image we will load and show on the screen

private:
	SDL_Window* m_gWindow;					//Member Window
	SDL_Surface* m_gScreenSurface;			//Member Screen Surface
	SDL_Surface* m_loadedImg;				//Member Image
	string m_imgName;						//Command Line Argument 

	SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

	SDL_Surface* loadSurface(string imgPath);
};

#endif

