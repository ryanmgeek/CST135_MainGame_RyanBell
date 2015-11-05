//Ryan Bell - cArrow.cpp

#include "cArrow.h"
const int ARROW_IMG_WIDTH = 1000; //Arrow-pointer image width (in pixels)
const int ARROW_IMG_HEIGTH = 173; //Arrow-pointer image height (in pixels)

								  //Enumerated list of possible angles the arrow position can be at
enum arrowPosition {
	LEFTMOST, LEFT35, LEFT30, LEFT25,
	LEFT20, LEFT15, LEFT10, LEFT5,
	MIDDLE,
	RIGHT5, RIGHT10, RIGHT15, RIGHT20,
	RIGHT25, RIGHT30, RIGHT35, RIGHTMOST,
	TOTALARROWPOSITIONS
};

const int SINGLE_ARROW_WIDTH = ARROW_IMG_WIDTH / TOTALARROWPOSITIONS;
//Single width of a arrow (as determined by the entire pic/#of arrows)
const int SINGLE_ARROW_HEIGTH = ARROW_IMG_HEIGTH / 1;
//Devision by 1 as a place holder (because there is only one row right now)


cArrow::cArrow()
{
	const int ARROW_POISTION_X = 800;   //constant x-position of where the 
										//arrow-pointer is going to be displayed 
										//on screen (in pixels)
	const int ARROW_POISITON_Y = 650;	//constant y-position of where the
										//arrow-pointer is going to be 
										//displayed on screen (in pixels)

	m_arrowRect.x = SINGLE_ARROW_WIDTH * MIDDLE; //Default Arrow pointer to 
												 //middle of Img (0 Degree tilt)
	m_arrowRect.y = 0;
	m_arrowRect.w = SINGLE_ARROW_WIDTH;
	m_arrowRect.h = SINGLE_ARROW_HEIGTH;

	m_arrowDestRect.x = ARROW_POISTION_X;
	m_arrowDestRect.y = ARROW_POISITON_Y;
	m_arrowDestRect.w = SINGLE_ARROW_WIDTH;
	m_arrowDestRect.h = SINGLE_ARROW_HEIGTH;
}

cArrow::~cArrow()
{
}

cArrow::cArrow(const cArrow & rightSide)
{
	m_arrowRect = rightSide.m_arrowRect;
	m_arrowDestRect = rightSide.m_arrowDestRect;
}

cArrow & cArrow::operator=(const cArrow & rightSide)
{
	if (this != &rightSide) //Check if A=A 
	{
		m_arrowRect = rightSide.m_arrowRect;
		m_arrowDestRect = rightSide.m_arrowDestRect;
	}
	return *this;
}

void cArrow::SetArrowRect(Direction moveDirection)
{
	//Check to see what direction the user wants to move the arrow pointer and 
	//make sure its not already as far as it can go to the left
	if (moveDirection == LEFT && m_arrowRect.x != SINGLE_ARROW_WIDTH* LEFTMOST)
	{
		m_arrowRect.x = m_arrowRect.x - SINGLE_ARROW_WIDTH;
	}
	//Check to see what direction the user wants to move the arrow pointer and 
	//make sure its not already as far as it can go to the right
	else if (moveDirection == RIGHT
		&& m_arrowRect.x != SINGLE_ARROW_WIDTH* RIGHTMOST)
	{
		m_arrowRect.x = m_arrowRect.x + SINGLE_ARROW_WIDTH;
	}
	//If function is called with any other movement passed, 
	//default arrow pointer back to middle (0 degree tilt)
	else if (moveDirection == DEFAULT)
	{
		m_arrowRect.x = SINGLE_ARROW_WIDTH * MIDDLE;
	}
}

const SDL_Rect& cArrow::GetArrowSrcRect() const
{
	return m_arrowRect;
}

const SDL_Rect & cArrow::GetArrowDestRect() const
{
	return m_arrowDestRect;
}
