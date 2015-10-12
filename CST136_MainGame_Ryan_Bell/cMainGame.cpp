//cMainGame.cpp
#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include <string>
#include "cMainGame.h"
#include "cKeyboard.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;


const int SCREEN_WIDTH = 640;						//Screen dimension constant for Width
const int SCREEN_HEIGHT = 480;						//Screen dimension constant for Height

													/******************************************************************************************
													*	Purpose: Construct game window and initialize members
													*
													*	Entry: MainGame object is instantiated
													*
													*	Exit: Each data member is initialized to passed data value
													*
													******************************************************************************************/
cMainGame::cMainGame(SDL_Window* gWindow, SDL_Surface* gScreenSurface,
	SDL_Surface* loadedImg, string imgName) : m_imgName(imgName),
	m_gWindow(gWindow), m_gScreenSurface(gScreenSurface), m_loadedImg(loadedImg)
{
}

/******************************************************************************************
*	Purpose: Default constructor if an object is instantiated to null parameters
*
*	Entry: MainGame object is instantiated
*
*	Exit: Each data member is initialized to null data value
*
******************************************************************************************/
cMainGame::cMainGame()
{
	SDL_Window* gWindow = m_gWindow = nullptr;
	SDL_Surface* gScreenSurface = m_gScreenSurface = nullptr;
	SDL_Surface* loadedImage = m_loadedImg = nullptr;
	string m_imgname = "\0";
}

/******************************************************************************************
*	Purpose: Destroy mainGame object
*
*	Entry: Object goes out of scope
*
*	Exit: Requested memory is freed and pointers set back to null
*
******************************************************************************************/
cMainGame::~cMainGame()
{
}

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
bool cMainGame::init()
{
	bool success = true;	//Initialization flag

	if (SDL_Init(SDL_INIT_VIDEO) < 0)	//Initialize SDL
	{
		cout << "SDL could not initialize! SDL_Error:" << SDL_GetError();
		success = false;
	}
	else
	{
		m_gWindow = SDL_CreateWindow(m_imgName.c_str(),					//Create Window
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (m_gWindow == nullptr)
		{
			cout << "Window could not be created! SDL_Error: \n" << SDL_GetError();
			success = false;
		}
		else
		{
			m_gScreenSurface = SDL_GetWindowSurface(m_gWindow);		//Get window surface
		}
	}

	return success;
}

/******************************************************************************************
*	Purpose: Loads BMP onto image surface
*
*	Entry: member function is called for object
*
*	Exit: image is loaded in image load surface, and checked for success.
*
******************************************************************************************/
bool cMainGame::loadMedia()
{
	bool success = true;	//Loading success flag

							//Load default surface
	gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("press.bmp");
	gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadSurface("up.bmp");
	gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = loadSurface("down.bmp");
	gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = loadSurface("left.bmp");
	gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadSurface("right.bmp");

	for (int i = 0; i < KEY_PRESS_SURFACE_TOTAL; i++)
	{
		if (gKeyPressSurfaces[i] == nullptr)
		{
			cout << "Failed to load default image!\n";
			success = false;
		}
	}

	m_loadedImg = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];		//Load splash image
	return success;
}

/******************************************************************************************
*	Purpose: Deallocate resources and free memory
*
*	Entry: member is function is called for mainGame object
*
*	Exit: Image surface, window, and SDL are freed from memory and pointer nulled
*
******************************************************************************************/
void cMainGame::close()
{

	SDL_FreeSurface(loadedImg);	//Deallocate surface
	loadedImg = nullptr;

	SDL_DestroyWindow(gWindow);	//Destroy window
	gWindow = nullptr;

	SDL_Quit();					//Destroy window
}

/******************************************************************************************
*	Purpose: Control Game loop
*
*	Entry: Member function is called for mainGame object
*
*	Exit: Keeps game running until enters Quit
*
******************************************************************************************/
void cMainGame::GameLoop()
{
	bool quitGame = false;
	SDL_Event sdlEvents;													//Event handler
	cKeyboard theKeyboard;									       //The keyboard class obj

	while (!quitGame)										 //While application is running
	{

		while (SDL_PollEvent(&sdlEvents) != 0)					   //Handle events on queue
		{
			if (sdlEvents.type == SDL_QUIT)
			{
				quitGame = true;
			}
			else if (sdlEvents.type = SDL_KEYDOWN)
			{
				m_loadedImg = theKeyboard.InterpretInput(sdlEvents, gKeyPressSurfaces);
			}

		}

		SDL_BlitSurface(GetLoadedImg(), NULL, GetgScreenSurface(), NULL);   //Apply the image
		SDL_UpdateWindowSurface(m_gWindow);							   //Update the surface
	}

	cout << "Terminating game, and saving level data...\n";

}

/******************************************************************************************
*	Purpose: __________________________________________
*
*	Entry: ____________________________________________
*
*	Exit: _____________________________________________
*
******************************************************************************************/
SDL_Surface* cMainGame::loadSurface(string imgPath)
{
	//Load image at specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP(imgPath.c_str());

	if (loadedSurface == nullptr)
	{
		cout << "Unable to load image " << imgPath << "\n! SDL Error: " << SDL_GetError();
	}

	return loadedSurface;
}

/******************************************************************************************
*	Purpose: Get member Image surface
*
*	Entry: Member function is called for mainGame object
*
*	Exit: returns loadedImg member surface for object
*
******************************************************************************************/
SDL_Surface* cMainGame::GetLoadedImg()
{
	return m_loadedImg;
}

/******************************************************************************************
*	Purpose: Get member screen Surface
*
*	Entry: Member function is called for mainGame object
*
*	Exit: Returns screen surface member for object
*
******************************************************************************************/
SDL_Surface* cMainGame::GetgScreenSurface()
{
	return m_gScreenSurface;
}

/******************************************************************************************
*	Purpose: Get member window
*
*	Entry: Member function is called for mainGame object
*
*	Exit: Returns window member for object
*
******************************************************************************************/
SDL_Window* cMainGame::GetgWindow()
{
	return m_gWindow;
}
