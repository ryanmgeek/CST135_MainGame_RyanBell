//cMainGame.cpp
#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include <string>
#include "cMainGame.h"
#include "cKeyboard.h"
#include "cSurfaceManager.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

cMainGame::cMainGame() {}
cMainGame::~cMainGame(){}

bool cMainGame::init()
{
	bool success = true;				//Initialization flag
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0 )	//Initialize SDL
	{
		cout << "SDL could not initialize! SDL_Error:" << SDL_GetError();
		success = false;
	}

	return success;
}


void cMainGame::close()
{
	SDL_Quit();					//Destroy window
}

void cMainGame::GameLoop(cSurfaceManager windowObj)
{
	bool quitGame = false;
	SDL_Event sdlEvents;													//Event handler

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
				windowObj.SetWindow(sdlEvents);
			}

		}

		
	}

	cout << "Terminating game, and saving level data...\n";

}
