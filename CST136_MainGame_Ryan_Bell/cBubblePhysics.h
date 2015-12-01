//  Ryan Bell - cBubble.h
/***********************************************************************
* Class: cBubble
*
* Constructors:
* -------------
*	cBubblePhysics();
*	********************************************************************
*	 Purpose: Create physcicsEngine and intialize data memebers
*	 Entry:	  A cBubble is instatied
*	 Exit:	  Creats a PhysicsEngine for a bubble object with defualt
*			  data memebers
*	********************************************************************
*	~cBubblePhysics();
*	********************************************************************
*	 Purpose:	Destroys physicsEngine
*	 Entry:		cBubble object leaves scope of the program
*	 Exit:		cBubblePhysics data members are nulled
*	********************************************************************
*	cBubblePhysics(const cBubblePhysics& rightSide);
*	********************************************************************
*	 Purpose:	Deep copy any invoking object's data memebrs
*	 Entry:		object is passed by value or declares a copy of an object
*	 Exit:		A deeply copy cBubblePhysics object is returned  from the
*				passed cBubblePhysics
*	********************************************************************
* Mutators:
* ---------
NA
* Methods
* ---------------
* 	cBubblePhysics& operator = (const cBubblePhysics& rightSide);
*	********************************************************************
*	 Purpose:	Set a cBubblePhysics object equal to a another cBubblePhysics
*	 Entry:		Equals operator is used between two cBubblePhysics
*	 Exit:		destination's cBubblePhysics members are set equal to another
*				cBubblePhysics
*	********************************************************************
*  void CalculateVector();
*	********************************************************************
*	 Purpose:	Calculate the vector for the current buble being shot
*	 Entry:		A bubble is shot
*	 Exit:		The x-offset and y-offset for moving the bubble are
*				determined using the standard math libries
*	********************************************************************
*	bool CheckVector(int x, int y);
*	********************************************************************
*	 Purpose:	Checks to make sure that the cordiantes that are going
*				to be printed at are within the playfeild
*	 Entry:		A new vector for a bubble is determined and the vector
*				needs to be checked if it has reached a wall, in which
*				case it will be roated 180 degrees
*	 Exit:		A boolean is returned weather the bubble has reached
*				the "Ceiling" of the play feild and weather or not a flip
*				around the shooting angle was required
***********************************************************************/

#ifndef CBUBBLEPHYSICS
#define CBUBBLEPHYSICS
#include <cmath>

const int SCREEN_WIDTH = 1920;													// Screen Size -width (in pixels)
const int SCREEN_HEIGHT = 1080;													// Screen Size - height (in pixels)
const int BUBBLE_PXL_BOARDER_SPACING = 24;										// Number of pixels on the boarder
const int SINGLE_BUBBLE_SIZE = 96;												// Pixel radius of a single bubble
const int FIRED_BUBBLE_X = (SCREEN_WIDTH / 2) - (SINGLE_BUBBLE_SIZE / 2) + 1;	// Fired bubble x Coordinate in pixels
const int FIRED_BUBBLE_Y = SCREEN_HEIGHT - SINGLE_BUBBLE_SIZE - 7;				// Fired bubble y Coordinate in pixels
const int LENGTH_OF_ARROW = 185;												// Length in pixels of the shooter arrow image
const int AREAOFTRIANGLE = 180;													// All of the angles of a triangle added together to compute area
const int RIGHTTRIANGLEANGLE = 90;												// Right triangle vertical angle 
const double PI = 3.141592653589793;											// Delicious and yummy pie 
const int PIXELS_TO_MOVE_BUBBLE_PERSECOND = 50;									// How many pixels per second a bubble will move, when fired
const int LEFT_EDGE_PLAYFEILD = 576;											// The left most edge that bubbles will collide with in pixels
const int RIGHT_EDGE_PLAYFEILD = 1344 - SINGLE_BUBBLE_SIZE;						// The right most edge that bubbles will collide with in pixel
const int BUBBLE_PXL_OFFSET_EVEN_Y = 84;										// Number of pixels to offset the height of even rows
const int BUBBLE_PXL_OFFSET_ODD_Y = 82;											// Number of pixels to offset the heigt of odd rows
const int BUBBLE_ARRAY_ROWS_Y = 11;												// Max number of rows of bubbles (0-10)
const int BUBBLE_ARRAY_EVEN_X = 8;												// Max number of bubbles in an even row (0,2,4,6,8,10)
const int BUBBLE_ARRAY_ODD_X = 7;												// Max number of bubbles in an odd row (1,3,5,7,9)
const int BUBBLE_PXL_OFFSET_EVEN_X = 576;										// Number of pixels to offset even rows
const int BUBBLE_PXL_OFFSET_ODD_X = 624;										// Number of pixels to offset odd rows			

class cBubblePhysics
{
	friend class cBubble;
public:
	cBubblePhysics();
	~cBubblePhysics();
	cBubblePhysics(const cBubblePhysics & rightSide);
	cBubblePhysics & operator=(const cBubblePhysics &rightSide);

	void CalculateVector();
	bool CheckVector(int x, int y, cBubble** bubbleArray[]);
private:
	double m_xMovemenet;
	//The calculated amount of pixels to shift along the x-axis
	double m_yMovement;
	//The calculated amount of pixels to move along the y-axis
	int m_shotAtDegree;
	//The initial degree that the bubble was fired at
	double m_yPixelCount;
	//The carry over from moving along the y axis with a double value  
	double m_xPixelCount;
	//The carny over from moving along the x axis with a double value
	bool m_bubbleReachedEnd;
	//Boolean weather the bubble has reached the end of the screen
};

#endif