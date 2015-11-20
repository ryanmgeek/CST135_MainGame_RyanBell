//Ryan Bell

#include "cStaticBubble.h"

cStaticBubble::cStaticBubble(SDL_Renderer * m_gRenderer)
{
	m_bubbleType = STATIC;
	LoadBubbleMedia( m_gRenderer);
}

cStaticBubble::~cStaticBubble()
{
}

void cStaticBubble::IncreaseTouching(cBubble ** bubbleArray[], 
													SDL_Renderer * m_gRenderer)
{
}

void cStaticBubble::DisplayPopAnimation()
{
}


