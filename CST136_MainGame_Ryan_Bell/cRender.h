//!+++ Ryan Bell - cRender.h
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
*	cArrow& GetArrowObject();
*	********************************************************************
*	 Purpose:	Get current Arrow object
*	 Entry:		Method is called by an invoking class
*	 Exit:		Arrow object is returned
*	********************************************************************
*
* Methods
* ---------------
* void DisplayCurrentPlayFeild(cBubble ** bubbleArray[]);
*	********************************************************************
*	 Purpose:	Display current play field to screen
*	 Entry:		Method is called by an invoking class
*	 Exit:		Current play field is displayed to screen
*	********************************************************************
*	bool Initalize();
*	********************************************************************
*	 Purpose:	Initalize data memebers and start SDL libraries
*	 Entry:		Is called by constuctor on instation
*	 Exit:		boolean is returned for success and data
memebers/ objs are successfully instatiatied
*	********************************************************************
*	bool LoadMedia();
*	********************************************************************
*	 Purpose:	Load Media images into textures
*	 Entry:		Method is called by constuctor
*	 Exit:		Texture array is filled with loaded images, boolean
*				of success is returned
***********************************************************************/

#ifndef CRENDER_H
#define CRENDER_H

#include "cBubble.h"
#include "cArrow.h"

static const int NUM_OF_ROWS_Y = 11;	// Number of rows of possible bubbles
static const int NUM_BUBBLES_EVEN = 8;	// Number of bubbles for every even row
static const int NUM_BUBBLES_ODD = 7;	// Number of bubbles for every odd row

class cRender
{
	enum numTextrues { PLAYFIELD, BUBBLEIMG, DIRECTIONARROWS, totalTextures };
	// enumerated list (location within the array of textures)
public:
	cRender();
	~cRender();
	cArrow& GetArrowObject();
	void DisplayCurrentPlayFeild(cBubble ** bubbleArray[]);

private:
	bool Initalize();
	// Method only called in object's constructor on instantiation
	bool LoadMedia();
	// Method only called in object's constructor on instantiation

	cArrow m_arrow; //  Only Arrow-pointer to be displayed

	SDL_Window* m_gWindow;				         // Main Game window
	SDL_Renderer* m_gRenderer;	               // Main Game renderer
	SDL_Texture* m_gTextures[totalTextures] = {};           // All game textures
};

#endif
