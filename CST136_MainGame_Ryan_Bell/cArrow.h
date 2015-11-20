// Ryan Bell - cArrow.h
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
*	cArrow(SDL_Renderer * m_gRenderer);
*	********************************************************************
*	 Purpose:	Construct arrow object with a renderer
*	 Entry:		object is instatied by  cRenderer class
*	 Exit:		Constructs a cArrow object with refrence to the passed renderer
*	********************************************************************
* Mutators:
* ---------
*	N/A
* Methods
* ---------------
* 	cArrow& operator = (const cArrow& rightSide);
*	********************************************************************
*	 Purpose:	Set a cArrow object equal to a another cArrow object
*	 Entry:		Equals operator is used between two arrow objects
*	 Exit:		Destination's cArrow members are set equal to another
*				cArrow object
*	********************************************************************
* 	void RenderArrow(SDL_Renderer * m_gRenderer);
*	********************************************************************
*	 Purpose:	Render cArrow object to renderer buffer
*	 Entry:		Is called by the cRenderer class for a cArrrow object
*	 Exit:		The current cArrow object is loaded to the renderer with
*				a point of rotation and the current degree of roation taken
*				taken into account,.
***********************************************************************/
#ifndef CARROW_H
#define CARROW_H
#include <SDL.h>
#include <SDL_image.h>
#include "cBubblePhysics.h"

enum Direction {
	LEFT, RIGHT, DEFAULT
};


const int PIXEL_OFFSET_ROTATION = 144;
//Roation along y axis that needs to be offset

char * const ARROW_IMG_PATH = "BubbleShooterArrow.png";
//Path of arrow img

class cArrow
{
	friend class cRender;
public:
	~cArrow();
	cArrow();
	cArrow & operator =(const cArrow & rightSide);
	cArrow(const cArrow & rightSide);
	cArrow(SDL_Renderer * m_gRenderer);
	void RenderArrow(SDL_Renderer * m_gRenderer);



private:
	SDL_Texture * m_arrowTexture;	//Texture of the arrow-pointer
	SDL_Rect m_destinationRectangle;//Rectangle of where to display to
	SDL_Point m_rotationPoint;		//Point torotatoe arrow about
	int m_degreesRotation;		//Degrees of roation from vertial 

};
#endif
