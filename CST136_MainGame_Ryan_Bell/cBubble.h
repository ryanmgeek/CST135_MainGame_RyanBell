//!+++  Ryan Bell - cBubble.h
/***********************************************************************
* Class: cBubble
*
* Constructors:
* -------------
*	cBubble();
*	********************************************************************
*	 Purpose: Create bubble of random color and intialize data memebers
*	 Entry:	  cBubble is instatied without a passed parameter
*	 Exit:	  Creats a cBubble object with defualt data memebers
*	********************************************************************
*	cBubble(bubbleColor passedColor);
*	********************************************************************
*	 Purpose:	Creates a bubble based on passed color
*	 Entry:		cBubble object is istatiated with a color provided
*	 Exit:		Creats a cBubble object with initalized data memebers
*	********************************************************************
*	~cBubble();
*	********************************************************************
*	 Purpose:	Destroys bubble
*	 Entry:		cBubble object leaves scope of the program
*	 Exit:		cBubble data memebers are nulled
*	********************************************************************
*	cBubble(const cBubble& rightSide);
*	********************************************************************
*	 Purpose:	Deep copy any invoking object's data memebrs
*	 Entry:		object is passed by value or declares a copy of an object
*	 Exit:		A deeply copy cBubble object is returned  from the
*				passed cBubble
*	********************************************************************
* Mutators:
* ---------
*	void IncreaseTouching(int passedIncreaseAmount = 1);
*	********************************************************************
*	 Purpose:	Increase touch count of a cBubble with its same colors
*	 Entry:		cBubble collides with it's same color
*	 Exit:		Touching data member is increased by passed amount
*	********************************************************************
*	int GetTouchingCount();
*	********************************************************************
*	 Purpose:	Get current touching value of a cBubble
*	 Entry:		Method is invoked by a calling class for a cBubble
*	 Exit:		cBubbles data memeber m_touching is returned
*	********************************************************************
*	const SDL_Rect& GetSourceRect() const;
*	********************************************************************
*	 Purpose:	Get the source rectangle of where to draw from
*	 Entry:		Method is invoked by a calling class for a cBubble
*	 Exit:		Method returns a const of the bubbles source Rectangle
*	********************************************************************
*	const SDL_Rect& GetDestinationRect() const;
*	********************************************************************
*	 Purpose:	Get the destination rectangle of where to draw to
*	 Entry:		Method is invoked by a calling class for a cBubble
*	 Exit:		Method returns a const of the bubbles destination rectangle
*	********************************************************************
*	void SetDestinationRect(int xCordPx, int yCordPx);
*	********************************************************************
*	 Purpose:	Set the cBubbles destion SDL rectangle of where to be
printed on the screen
*	 Entry:		Method is invoked by a calling class for a cBubble
*	 Exit:		cBubbles destination is set to the passed cordinates
or an error is thrown
*	********************************************************************
* Methods
* ---------------
* 	cBubble& operator = (const cBubble& rightSide);
*	********************************************************************
*	 Purpose:	Set a cBubble object equal to a another cBubble object
*	 Entry:		Equals operator is used between two bubbles
*	 Exit:		destination's cBubble members are set equal to another
*				cBubble
***********************************************************************/

#ifndef CBUBBLE_H
#define CBUBBLE_H
#include <SDL.h>

enum bubbleColor { RED, ORANGE, GREEN, BLUE, PURPLE, BLACK, TOTALBUBBLES };
//  Possible bubble colors as seen in the bubble.bmp

const int BUBBLE_IMG_WIDTH = 626; //  entire bubble.bmp image height (in pixels)
const int BUBBLE_IMG_HEIGTH = 97; //  entire bubble.bmp image heigth (in pixels)

const int SINGLE_BUBBLE_W = BUBBLE_IMG_WIDTH / TOTALBUBBLES;
//  Width of a single bubble object
const int SINGLE_BUBBLE_H = BUBBLE_IMG_HEIGTH / 1;
//  Height of a single bubble object // Only one row of bubbles currently

class cBubble
{
public:
	cBubble();
	~cBubble();
	cBubble(bubbleColor passedColor);
	cBubble(const cBubble& rightSide);
	cBubble& operator = (const cBubble& rightSide);

	void IncreaseTouching(int passedIncreaseAmount = 1);
	//  consider overloading the + operator
	int GetTouchingCount();
	const SDL_Rect& GetSourceRect() const;
	const SDL_Rect& GetDestinationRect() const;
	void SetDestinationRect(int xCordPx, int yCordPx);

private:
	SDL_Rect m_sourceRect;
	//  Source Rectangle -Loaction of where to draw from the bubble texture
	//  These can't be base memeber intialized to a zero/null
	SDL_Rect m_destinationRect; //  Destination rectangle - Loaction of
								//  where to draw the bubble on the screen
								//  These can't be base memeber intialized
								//  to a zero/null
	bubbleColor m_bubbleColor;
	//  Enumerated number signifying bubble color Red, Orange,etc..
	int m_touchingBubblesCount;
	//  Number of bubbles touching their same color
};

#endif