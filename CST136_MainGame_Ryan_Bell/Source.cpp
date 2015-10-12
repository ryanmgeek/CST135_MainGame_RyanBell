//Main.cpp
/******************************************************************************************
* Author:							Ryan Bell
* Date Created:						9/27/15
* Last Modification Date:			10/01/15
* Lab Number:						CST 136 Lab 1
* Filename:							CST136_lab1_Ryan Bell_Main.cpp
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

		cMainGame mainGameWindow(gWindow, gScreenSurface, loadedImg, argv[1]); //Create Obj

		if (!mainGameWindow.init())				//Start up SDL and create window
		{
			cout << "Failed to initialize!\n";
		}
		else
		{
			if (!mainGameWindow.loadMedia())	//Load media
			{
				cout << "Failed to load media!\n";
			}
			else
			{

				SDL_BlitSurface(mainGameWindow.GetLoadedImg(),		   //Apply the image
					NULL, mainGameWindow.GetgScreenSurface(), NULL);

				SDL_UpdateWindowSurface(mainGameWindow.GetgWindow());  //Update the surface	
				mainGameWindow.GameLoop();							   //Enter Game loop
				SDL_Delay(2000);									   //Wait two seconds
																	   //Call game Loop Function
			}
		}

		mainGameWindow.close();								//Free resources and close SDL
	}

	return 0;
}



