//!+++  Ryan Bell - cGameEngine.h
/***********************************************************************
* Class: cGameEngine
*
* Constructors:
* -------------
*	cGameEngine();
*	********************************************************************
*	 Purpose: Allocate space for bubble array
*	 Entry:	  cGameEngine object is instantiated
*	 Exit:	  creates a ragged array of bubbles
*	********************************************************************
*	~cRender();
*	********************************************************************
*	 Purpose:	Destroy allocated bubbles
*	 Entry:		cRender object leaves scope of the program
*	 Exit:		Bubbles objects are deleted and array is nulled
*	********************************************************************
*
* Mutators:
* ---------
*	Not Applicable
*
* Methods
* ---------------
* 	void BeginGame();
*	********************************************************************
*	 Purpose:	Begins game loading first rows of bubbles and bubble
to be fired
*	 Entry:		Method is invoked for a cGameEngine Object
*	 Exit:		Initial game variables are set and bubble array filled
*	********************************************************************
*	void RunGameLoop();

*	********************************************************************
*	 Purpose:	Run a game loop until user exits or wins
*	 Entry:		Method is invoked by main for a cGameEngine object
*	 Exit:		Game loop runs interpreting user input and calling
*				display
***********************************************************************/

#ifndef CGAMEENGINE_H
#define CGAMEENGINE_H
#include "cRender.h"

class cGameEngine
{
public:
	cGameEngine();
	~cGameEngine();

	void BeginGame();
	void RunGameLoop();
private:
	cRender m_gameRender;						 // Main Game renderer object
	cBubble ** m_bubbleArray[NUM_OF_ROWS_Y] = {}; // Main Bubble array
};
#endif
