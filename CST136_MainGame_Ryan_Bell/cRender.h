// Ryan Bell - cRender.h

/***********************************************************************
* Class: cRender

* Constructors:
* -------------
*	cRender();
*	********************************************************************
*	 Purpose: Initialize SDL libraries and starting values and Load media
*	 Entry:	  cRender object is instantiated
*	 Exit:	  Displays if any errors occurred to console
*	********************************************************************
*	~cRender();
*	********************************************************************
*	 Purpose:	Destroy allocated textures and data members
*	 Entry:		cRender object leaves scope of the program
*	 Exit:		SDL textures are destroyed and nulled, renderer is
*				destroyed and nulled, window is destroyed and nulled,
*				SDL libraries is quit.
*	********************************************************************
*
* Mutators:
* ---------
*	cBubble *** GetBubbleArray();
*	********************************************************************
*	 Purpose:	Get current Bubble Array
*	 Entry:		Method is called by an invoking class
*	 Exit:		bubbleArray is returned
*	********************************************************************
*	SDL_Renderer * GetRenderer();
*	********************************************************************
*	 Purpose:	Get Renderer
*	 Entry:		Method is called by an invoking class
*	 Exit:		Game Renderer is returned
*	********************************************************************
*	void SetFiredBuble(cBubble *);
*	********************************************************************
*	 Purpose:	Set current fired bubble object
*	 Entry:		Method is called by an invoking class
*	 Exit:		Fired bubble object is updated to match passed bubble
*	********************************************************************
*	void SetArrowPosition(const Direction & moveDirection);
*	********************************************************************
*	 Purpose:	Set current Arrow object tilt
*	 Entry:		Method is called by an invoking class
*	 Exit:		Arrow object is incramented in passed move direction
*	********************************************************************
* Methods
* ---------------
*	bool LoadMedia();
*	********************************************************************
*	 Purpose:	Load Media images into textures
*	 Entry:		Method is called by constuctor
*	 Exit:		Texture array is filled with loaded images, boolean
*				of success is returned
***********************************************************************
*	bool Initalize();
*	********************************************************************
*	 Purpose:	Initalize data memebers and start SDL libraries
*	 Entry:		Is called by constuctor on instation
*	 Exit:		boolean is returned for success and data
*				memebers/ objs are successfully instatiatied
***********************************************************************/

#ifndef CRENDER_H
#define CRENDER_H
#include "cArrow.h"
#include "cBubble.h"



char * const GAME_NAME = "Techno Bubble Puzzle";	// Name of the game
char* const BACKGROUND_IMAGE_PATH [] = {"Backsplash.png", "Background.png"};
										//Image paths to backgrounds 
enum IMAGE_PATHS {BACKSPASH, BACKGROUND, TOTAL_BACKGROUNDS};
										//Index of array of background textures  


const int MAX_ARROW_DEGREE = 80;				//Max Incline of arrow possible

class cRender
{
	friend class cGameEngine;
public:
	cRender();
	~cRender();

	void DisplayCurrentPlayField();
	cBubble *** GetBubbleArray();
	SDL_Renderer * GetRenderer();
	void SetFiredBuble(cBubble *);
	void SetArrowPosition(const Direction & moveDirection);


private:
	bool Initalize();
	bool LoadMedia();

	cBubble ** m_bubbleArray[BUBBLE_ARRAY_ROWS_Y];		//MAIN buble array
	cArrow * m_shooterArrow;						//Bubble shooter graphic
	cBubble * m_firedBubble;					//Bubble being fired 

	SDL_Window * m_gWindow;						// Main Game window
	SDL_Renderer * m_gRenderer;				// Renderer linked to main window
	SDL_Texture * m_gTextures[TOTAL_BACKGROUNDS];	//background textures

	bool m_userFiredABubble;
	int m_frameCount;
};

#endif

