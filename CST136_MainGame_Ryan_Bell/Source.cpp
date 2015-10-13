//Main.cpp
/******************************************************************************************
* Author:							Ryan Bell
* Date Created:						10/06/15
* Last Modification Date:			10/12/15
* Lab Number:						CST 136 Lab 2
* Filename:							CST136_lab2_Ryan Bell
*
*	Overview:
*	---------
*		This is a basic program displaying the use of a external SDL2 library, and
*		using it to display a single image the screen. While also modeling a
*		theoretical game loop.
*
*	Input:
*	------
*		Once a basic image is displayed to the screen as the user input may enter whatever
*		they desire whist they "play the game." The only input required is a the string
*		"Quit" once they wish to terminate the program.
*
*   Output:
*	-------
*		A image determined by a command line argument is displayed in a separate windows
*		that is 640px x 480px.
******************************************************************************************/

#include <SDL.h>	//Using SDL and standard IO
#include <stdio.h>
#include <iostream>
#include "cMainGame.h"
#include "cSurfaceManager.h"
using std::cout;
using std::endl;



int main(int argc, char* argv[])
{

	if (argc <= 1)					  //Check to make sure command line argument was caught
	{
		cout << "No command Line arguments detected";
	}
	else
	{
		SDL_Window* gWindow = nullptr;			 //Initialize gWidow Pointer to null value
		SDL_Surface* gScreenSurface = nullptr;	 //Initialize gScreenSurface to null value
		SDL_Surface* loadedImg = nullptr;		 //Initialize loaded Image to null value

		cMainGame mainGame;						//Create Obj
		cSurfaceManager windowOne(gWindow, gScreenSurface, loadedImg, argv[1]);

		if (!mainGame.init() || !windowOne.loadMedia())	   //Start up SDL and create window
		{
			cout << "Failed to initialize!\n";
		}
		else
		{
			SDL_UpdateWindowSurface(windowOne.GetgWindow());	//Update the surface	
			mainGame.GameLoop(windowOne);						//Enter Game loop
			SDL_Delay(2000);									//Wait two seconds
		}

		windowOne.FreeSurfaces();								//Free resource & close SDL
		mainGame.close();								
	}

	return 0;
}



