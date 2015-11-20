//Ryan Bell
/***********************************************************************
* Author:							Ryan Bell
* Date Created:						09/02/15
* Last Modification Date:			11/16/15
* Lab Number:						CST 136 Lab 5
* Filename:							CST136_lab5_Ryan Bell
*
*	Overview:
*	---------
*		This is a basic program displaying the use of a external
*		SDL2 library, using this library the following project will
*		demonstrate Use of dynamic memory management to create new
*		objects, implementation of the orthodox conical class form,
*		demonstration of objects being dynamically created and
*		destroyed on screen, include a PVBC and ABC, and use SDL_Textures to move
*		objects on screen.
*
*	Input:
*	------
*		The input from the user consists of pressing the arrow keys
*		to play the game. Once they have fished they may press
*		the space bar to "fire" and end the game or press the x at
*		the top of the widow.
*
*			KEY BINDINGS:
*			-------------
*			Left-Arrow:		Move Arrow-pointer left
*			Right-Arrow:	Move Arrow-Pointer right
*			Up-Arrow:		Reset Arrow-Pointer to upright position
*			Down-Arrow:		Change incoming bubble color
*			Right-ctr:		Change First row bubbles to different color (cheat)
*			Escape:			End Game			
*
*   Output:
*	-------
*		The game field will be displayed to the screen along with
*		bubbles to be popped and the user's incoming bubble. The play
*		field will also have the Arrow-Pointer directing where the
*		fired bubble will go. 
******************************************************************************/

#define _CRTDBG_MAP_ALLOC // For Demonstration Purposes
#include <crtdbg.h>	// For demonstration Purposes
#include "cGameEngine.h"


int main (int argc, char * argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // For demonstration Purposes

	cGameEngine mainGame;				// Instantiate MainGame object
	mainGame.BeginGame();				// Startup game and load defaults
	mainGame.RunGame();					// Run main game loop
	return 0;
}