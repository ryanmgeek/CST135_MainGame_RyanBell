//  Ryan Bell - cBubble.h
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
*	const int& GetTouchingCount() const;
*	********************************************************************
*	 Purpose:	Get current touching value of a cBubble
*	 Entry:		Method is invoked by a calling class for a cBubble
*	 Exit:		cBubbles data memeber m_touching is returned
*	********************************************************************
*	void SetBubbleDestinationRectangle(int const &xCordinate,
*														int const &yCordinate);
*	********************************************************************
*	 Purpose:	Set the cBubbles destion SDL rectangle of where to be
*				printed on the screen
*	 Entry:		Method is invoked by a cBubble type object
*	 Exit:		cBubbles destination is set to the passed cordinates
*				or an error is thrown
*	********************************************************************
*    void SetSurroundingBubbles(BUBBLE_LOCATION bubbleLocation,
*													 cBubble* nearbyBubble);
*	********************************************************************
*	 Purpose:	set the surounding bubble of a bubble at the passeed bubble
*				location to the passed bubble
*	 Entry:		CacluateTouching count is called
*	 Exit:		The passed bubble is loaded onto the current bubble's vector
*				at the passed BUBBLE_LOCATION
*	********************************************************************
*	void SetArrayLocations(int const &y, int const &x);
*	********************************************************************
*	 Purpose:  Set the bubble's arrayLocation data memenbbers
*	 Entry:	   Bubble is instatiated and its coorditaes in the array are needed
*	 Exit:	   The bubboles arrayLocation data memebers are set to
*			   the passed x and y values
*	********************************************************************
*	virtual void SetTouching(const int & newTouchCount);
*	********************************************************************
*	 Purpose:  Set the bubble's touchcount data memenbbers
*	 Entry:	  CalculateBubblesTouchCount is called for the bubblearray
*	 Exit:	  The bubble's count of how many of the same type of bubbles
*			  that it is touching is set to the passed value
*	********************************************************************
*	void SetVisted(const bool& updatedVisted);
*	********************************************************************
*	 Purpose:  Set the bubble's visted boolean
*	 Entry:	 CalcluateBubblesTouchVCount is called by Renderer
*	 Exit:	 The bubbles visted boolean is set to the passed boolean value
*	********************************************************************
*   void SetPrevious(cBubble * previousBubble);
*	********************************************************************
*	 Purpose:  Set the bubble's previous bubble pointer to the passed bubble
*	 Entry:	 CalcluateBubblesTouchVCount is called by Renderer
*	 Exit:	The bubble's previous bubble data memeber is set to the passed
*			cBubble
*	********************************************************************
* Methods
* ---------------
* 	cBubble& operator = (const cBubble& rightSide);
*	********************************************************************
*	 Purpose:	Set a cBubble object equal to a another cBubble object
*	 Entry:		Equals operator is used between two bubbles
*	 Exit:		destination's cBubble members are set equal to another
*				cBubble
*	virtual void SpecialEffect(cBubble ** bubbleArray[],
*												SDL_Renderer * m_gRenderer);
*	********************************************************************
*	 Purpose:	Animate Special effect corrsiponding to bubble type
*	 Entry:		Method uis abstract and is inovked by primarily
*				inheriting objects
*	 Exit:		Special effect is displayed based on bubble type
*	********************************************************************
*   virtual void IncreaseTouching(cBubble ** bubbleArray[],
*												   SDL_Renderer * m_gRenderer);
*	********************************************************************
*	 Purpose:	Increase the touch count of bubble
*	 Entry:		A new bubble is added to the array and the touch count needs
*				to be updated
*	 Exit:		The m_touchingCount is incramented based on proximety to
*				its matching colors, using a debth first search
*	********************************************************************
*	virtual void Pop(cBubble ** bubbleArray[], SDL_Renderer * m_gRenderer);
*	********************************************************************
*	 Purpose:	Pops all matching color types of that bubble based on proximety
*	 Entry:		New bubble of same color is added to the array or is
*				invoked by special effect
*	 Exit:		cBubble array is rearraged, bubles are destroyed, and object
*				calling pop is popped
*	********************************************************************
*	void RenderBubble(SDL_Renderer * m_gRenderer);
*	********************************************************************
*	 Purpose:	Render current bubble type to screen
*	 Entry:		Is called by a cRender object while displaying bubble to screen
*	 Exit:		A Bubble is rendered to the renderer buffer
*	********************************************************************
*	 void LoadBubbleMedia(SDL_Renderer * m_gRenderer);
*	********************************************************************
*	 Purpose:	Loads bubble media and surface for each bubble
*	 Entry:		is called on instationon of any bubble type
*	 Exit:		The surface is loaded for each bubble and the correct source
*				rectangle from the sprite sheet for that bubble
*				type is calculated
*	********************************************************************
*	void CalcualteBubbleVector(const int& arrowDegrees);
*	********************************************************************
*	 Purpose:	To calculate the vector on wich a shot bubble will travel
*	 Entry:		Is called once the user presses the space-bar
*	 Exit:		The bubble vector is calculated and the bubble is rendered
*				onto the renderer que
***********************************************************************/

#ifndef CBUBBLE_H
#define CBUBBLE_H
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "cBubblePhysics.h"
#include <vector>

const int BUBBLE_ARRAY_ROWS_Y = 11;
const int BUBBLE_ARRAY_EVEN_X = 8;
const int BUBBLE_ARRAY_ODD_X = 7;
const int BUBBLEIMG_BUBBLES_PER_ROW = 6;
const int BUBBLEIMG_BUBBLE_ROWS = 3;
const int MAX_SURROUNDING_BUBBLES = 6;
const int ARROW_ROTATION_INCRAMENT = 5;			//Amount to roatate arrow by

												//All possible bubble types
enum BUBBLE_TYPE
{
	RED, YELLOW, GREEN, BLUE, PURPLE, WHITE,
	RED_EQUAL, YELLOW_EQUAL, GREEN_EQUAL, BLUE_EQUAL, PURPLE_EQUAL, WHITE_EQUAL,
	RED_POP, YELLOW_POP, GREEN_POP, BLUE_POP, PURPLE_POP, WHITE_POP,
	FIRE, RANDOMRECOLOR, STATIC, TOTALBUBBLES
};
//Every Location a bubble can exsit at surrounding a bubble
enum BUBBLE_LOCATION
{
	RIGHT_HAND, LRIGHT, LLEFT, LEFT_HAND, ULEFT, URIGHT
};

//Bubble types cataries
enum BUBBLE_EFFECT
{
	SPECIAL, POP, EQUAL, CLAW
};


const int BUBBLES_PER_ROW = 6;	    //Bubbles per row in bubbble sprite sheet 


char* const BUBBLE_IMG_PATH = "Bubbles.png";	//Path to bubbble img

class cBubble
{
public:
	cBubble();
	virtual ~cBubble();
	cBubble & operator=(const cBubble &rightSide);
	cBubble(const cBubble & rightSide);

	virtual void SpecialEffect(cBubble ** bubbleArray[],
		SDL_Renderer * m_gRenderer);
	virtual void Pop(cBubble ** bubbleArray[], SDL_Renderer * m_gRenderer);
	void RenderBubble(SDL_Renderer * m_gRenderer);
	void CalcualteBubbleVector(const int& arrowDegrees);

	const BUBBLE_TYPE & GetBubbleType();
	const bool & GetVisted();
	const int & GetTouchCount(); //For demonstration purposes (press K)

	void SetBubbleDestinationRectangle(int const &xCordinate,
		int const &yCordinate);
	void SetArrayLocations(int const &y, int const &x);
	virtual void SetTouching(const int & newTouchCount);
	void SetVisted(const bool& updatedVisted);
	void SetPrevious(cBubble * previousBubble);
	void SetSurroundingBubbles(BUBBLE_LOCATION bubbleLocation,
		cBubble* nearbyBubble);

protected:
	int m_touchingBubbleCount;	//Number of bubbles touching of the same type
	const int & GetTouchingCount() const;
	void LoadBubbleMedia(SDL_Renderer * m_gRenderer);

	BUBBLE_TYPE m_bubbleType;		//Bubble type (SPECIAL, POP, EQUAL, CLAW )
	SDL_Rect m_sourceRectangle;		//Source of sprite sheet texture Rect
	SDL_Rect m_destinationRectangle; //Destination of printing to render rect
	int m_x;	 //X loaction in the bubble array
	int m_y;	 //Y location in the bubble array
private:
	cBubblePhysics * m_physicsEngine;		//Physics for the particual bubble
	SDL_Texture * m_bubbleTexture;			//Texture sheet for bubble
	bool m_visted;
	//vector of all surrounding bubbles
	cBubble * m_surroundingBubbles[5];
	cBubble * m_previousBubble;	//Pointer to previous bubble


};
#endif
