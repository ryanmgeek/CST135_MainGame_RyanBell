//Ryan Bell

#include "cFirePopBubble.h"

cFirePopBubble::cFirePopBubble(SDL_Renderer * m_gRenderer)
{
	m_bubbleType = FIRE; 
	LoadBubbleMedia( m_gRenderer);
}

cFirePopBubble::~cFirePopBubble()
{
}

void cFirePopBubble::DisplayPopAnimation()
{
}

void cFirePopBubble::SpecialEffect(cBubble ** bubbleArray[],
	                                                SDL_Renderer * m_gRenderer)
{
}

