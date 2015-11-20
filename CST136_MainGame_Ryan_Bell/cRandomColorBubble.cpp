//Ryan Bell

#include "cRandomColorBubble.h"

cRandomColorBubble::cRandomColorBubble(SDL_Renderer * m_gRenderer)
{
	m_bubbleType = RANDOMRECOLOR;
	LoadBubbleMedia( m_gRenderer);
}


cRandomColorBubble::~cRandomColorBubble()
{
}

void cRandomColorBubble::DisplayPopAnimation()
{
}

void cRandomColorBubble::SpecialEffect(cBubble ** bubbleArray[],
												    SDL_Renderer * m_gRenderer)
{
}
