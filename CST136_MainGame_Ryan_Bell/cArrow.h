//!+++ Ryan Bell - cArrow.h
/***********************************************************************
* Class: cArrow
*
* Constructors:
* -------------
*	cArrow();
*	********************************************************************
*	 Purpose: Create cArrow object with defualt arrow position
*	 Entry:	  cArrow object is instatiated
*	 Exit:	  cArrow object is created with default initlized values
*	********************************************************************
*	~cArrow();
*	********************************************************************
*	 Purpose:	Destroys cArrow object
*	 Entry:		cArrow object leaves scope of the program
*	 Exit:		cArrow data memebers are nulled
*	********************************************************************
*	cArrow(const cArrow& rightSide);
*	********************************************************************
*	 Purpose:	Deep copy any invoking object's data memebrs
*	 Entry:		object is passed by value or declares a copy of an object
*	 Exit:		A deeply copy cArrow object is returned from the
*				passed cArrow
*	********************************************************************
* Mutators:
* ---------
*	void SetArrowRect(Direction);
*	********************************************************************
*	 Purpose:	Increment cArrow's object in a direction
*	 Entry:		Method is called by invoking class for a cArrow object
*	 Exit:		cArrow's direction(tilt) is increased either left or right
*	********************************************************************
*	const SDL_Rect& GetArrowSrcRect() const;
*	********************************************************************
*	 Purpose:	Get the source rectangle of where to draw from
*	 Entry:		Method is invoked by a calling class for a cArrow object
*	 Exit:		Method returns a const of the cArrow source Rectangle
*	********************************************************************
*	const SDL_Rect& GetArrowDestRect() const;
*	********************************************************************
*	 Purpose:	Get the destination rectangle of where to draw to
*	 Entry:		Method is invoked by a calling class for a cArrow
*	 Exit:		Method returns a const of the cArrow's destination rectangle
*	********************************************************************
* Methods
* ---------------
* 	cArrow& operator = (const cArrow& rightSide);
*	********************************************************************
*	 Purpose:	Set a cArrow object equal to a another cArrow object
*	 Entry:		Equals operator is used between two arrow objects
*	 Exit:		Destination's cArrow members are set equal to another
*				cArrow object
***********************************************************************/

#ifndef CARROW_H
#define CARROW_H

#include <SDL.h>

enum Direction { LEFT, RIGHT, DEFAULT }; // Direction to move arrow (increment
										 //  or decrement by 5 degrees or set
										 // back to default)
class cArrow
{
public:
	cArrow();
	~cArrow();
	cArrow(const cArrow& rightSide);
	cArrow& operator = (const cArrow& rightSide);

	void SetArrowRect(Direction);
	const SDL_Rect& GetArrowSrcRect() const;
	const SDL_Rect& GetArrowDestRect() const;

private:
	SDL_Rect m_arrowRect; // Source rectangle (where on texture sprite // will be loaded from) // These can't be base memeber intialized to a zero/null
	SDL_Rect m_arrowDestRect; // Destination rectangle (Where on screen // arrow-pointer needs to be loaded to) // These can't be base memeber // intialized to a zero/null
};
// this is a long comment
#endif
