//Ryan Bell - Main.cpp
/***********************************************************************
* Author:							Ryan Bell
* Date Created:						10/25/15
* Last Modification Date:			11/02/15
* Lab Number:						CST 136 Lab 4
* Filename:							CST136_lab4_Ryan Bell
*
*	Overview:
*	---------
*		This is a basic program displaying the use of a external
*		SDL2 library, using this library the following project will
*		demonstrate Use of dynamic memory management to create new
*		objects, implementation of the orthodox conical class form,
*		demonstration of objects being dynamically created and
*		destroyed on screen, exemplification of two uses of overloading
*		the assignment operator, using SDL_Textures to put objects on
*		screen, and Show the use the sprite sheets.
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
*			Space-Bar:		"Fire" End Game
*
*   Output:
*	-------
*		The game field will be displayed to the screen along with
*		bubbles to be popped and the user's incoming bubble. The play
*		field will also have the Arrow-Pointer directing where the
*		fired bubble will go (if implemented). Once fired the widow
*		will show the destruction of all bubbles on screen.
***********************************************************************/

#define _CRTDBG_MAP_ALLOC
#include "cGameEngine.h"
#include <crtdbg.h> //For demonstration Purposes 

int main(int argc, char * argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//For demonstration Purposes 

	cGameEngine MainGame;				//Instantiate MainGame object
	MainGame.BeginGame();				//Startup game and load defaults
	MainGame.RunGameLoop();				//Run main game loop

	return 0;
}