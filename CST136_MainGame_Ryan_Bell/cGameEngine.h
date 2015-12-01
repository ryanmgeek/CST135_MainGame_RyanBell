//  Ryan Bell - cGameEngine.h
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
*				to be fired
*	 Entry:		Method is invoked for a cGameEngine Object
*	 Exit:		Initial game variables are set and bubble array filled
*	********************************************************************
*	void RunGameLoop();
*	********************************************************************
*	 Purpose:	Run a game loop until user exits or wins
*	 Entry:		Method is invoked by main for a cGameEngine object
*	 Exit:		Game loop runs interpreting user input and calling
*				display
*	void GetNewBubble();
*	********************************************************************
*	 Purpose:	Get a new bubble to fire at bubble array
*	 Entry:		Method is invoked by cGameEngine
*	 Exit:		A new bubble type is replaced with current bubble being fired
*				Unless the type of the currently being fired bubble is a
*				regular bubble.
*   *******************************************************************
*	void HackGame();
*	********************************************************************
*	 Purpose:	Hack the top row of bubbles to be a more desirable color
*	 Entry:		Method is invoked by cGameEngine
*	 Exit:		A new regular cBubble is created and cast to a location in the
*				first row of the bubble Array
*   *******************************************************************
*	 cBubble * GenerateBubble();
*   *******************************************************************
*	 Purpose:	Genrate a new bubble type
*	 Entry:		Method is invoked by cGameEngine
*	 Exit:		A new bubble type is instatiated from a random
*				number and returned
***********************************************************************/

#ifndef CGAMEENGINE_H
#define CGAMEENGINE_H
#include "cRender.h" 

const int NUMBER_OF_START_ROWS = 6;	   // Rows of bubbles to start the game with

class cGameEngine
{
public:
	cGameEngine();
	~cGameEngine();

	void BeginGame();
	void RunGame();

private:
	void GetNewBubble();
	void HackGame();
	cBubble * GenerateBubble();
	cRender * m_gameRender;	// GameRenderer object to render/ manager surfaces


};

#endif 