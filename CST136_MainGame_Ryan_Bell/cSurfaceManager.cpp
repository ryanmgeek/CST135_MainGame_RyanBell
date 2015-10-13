#include <iostream>
#include "cSurfaceManager.h"
#include "cKeyboard.h"

using std::cout;
using std::string;

const int SCREEN_WIDTH = 640;						//Screen dimension constant for Width
const int SCREEN_HEIGHT = 480;						//Screen dimension constant for Height

cSurfaceManager::cSurfaceManager ( SDL_Window* gWindow, SDL_Surface* gScreenSurface,
SDL_Surface* loadedImg, string imgName) : m_imgName(imgName),
m_gWindow(gWindow), m_gScreenSurface(gScreenSurface), m_loadedImg(loadedImg) {}

cSurfaceManager::cSurfaceManager()
{
	SDL_Window* gWindow = m_gWindow = nullptr;
	SDL_Surface* gScreenSurface = m_gScreenSurface = nullptr;
	SDL_Surface* loadedImage = m_loadedImg = nullptr;
	string m_imgname = "\0";
}

cSurfaceManager::~cSurfaceManager()
{
}


bool cSurfaceManager::loadMedia()
{
	bool success = true;	//Loading success flag

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

	m_gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("press.bmp");
	m_gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadSurface("up.bmp");
	m_gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = loadSurface("down.bmp");
	m_gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = loadSurface("left.bmp");
	m_gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadSurface("right.bmp");

	for (int i = 0; i < KEY_PRESS_SURFACE_TOTAL; i++)
	{
		if (m_gKeyPressSurfaces[i] == nullptr)
		{
			cout << "Failed to load default image!\n";
			success = false;
		}
	}

	m_loadedImg = m_gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];		//Load splash image
	return success;
}

SDL_Surface* cSurfaceManager::loadSurface(string imgPath)
{
	//Load image at specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP(imgPath.c_str());

	if (loadedSurface == nullptr)
	{
		cout << "Unable to load image " << imgPath << "\n! SDL Error: " << SDL_GetError();
	}

	return loadedSurface;
}

void cSurfaceManager::SetWindow(SDL_Event sdlEvents)
{
	cKeyboard theKeyboard;									       //The keyboard class obj
	m_loadedImg = theKeyboard.InterpretInput(sdlEvents, m_gKeyPressSurfaces);

	SDL_Surface* optimizedSurface = nullptr;

	optimizedSurface = SDL_ConvertSurface(m_loadedImg, m_gScreenSurface->format, NULL);
	if (optimizedSurface == nullptr)
	{
		cout<<"Unable to optimize image SDL Error: \n"<< SDL_GetError();
	}
	
	SDL_Rect stretchRect;
	stretchRect.x = 0;
	stretchRect.y = 0;
	stretchRect.w = SCREEN_WIDTH;
	stretchRect.h = SCREEN_HEIGHT;

	SDL_BlitSurface(optimizedSurface, NULL, m_gScreenSurface, NULL); //Apply the image
	SDL_BlitScaled(optimizedSurface, NULL, m_gScreenSurface, &stretchRect); //stretch the surface
	SDL_UpdateWindowSurface(m_gWindow);							   //Update the surface
	
	m_loadedImg = optimizedSurface;

	SDL_FreeSurface(optimizedSurface);
	optimizedSurface = nullptr;
}

void cSurfaceManager::FreeSurfaces()
{
	for (int i = 0; i < KEY_PRESS_SURFACE_TOTAL; i++)
	{
		SDL_FreeSurface(m_gKeyPressSurfaces[i]);		//Frees all SDL surfaces 
		m_gKeyPressSurfaces[i] = nullptr;
	}

	SDL_FreeSurface(m_loadedImg);	//Deallocate surface
	m_loadedImg = nullptr;

	SDL_DestroyWindow(m_gWindow);	//Destroy window
	m_gWindow = nullptr;
}

SDL_Surface* cSurfaceManager::GetLoadedImg()
{
	return m_loadedImg;
}

SDL_Surface* cSurfaceManager::GetgScreenSurface()
{
	return m_gScreenSurface;
}

SDL_Window* cSurfaceManager::GetgWindow()
{
	return m_gWindow;
}