//Ryan Bell

#include "cRegularBubble.h"

cRegularBubble::cRegularBubble(SDL_Renderer * m_gRenderer)
{
	// Genrate a random color of a regular bubble type 
	m_bubbleType = static_cast<BUBBLE_TYPE>(rand() % RED_EQUAL);
	LoadBubbleMedia(m_gRenderer);
}

cRegularBubble::cRegularBubble(SDL_Renderer * m_gRenderer, BUBBLE_TYPE bubbleType)
{
	if (bubbleType < RED || bubbleType > WHITE)
	{
		std::cout << "A invalid bubble type was attempted to be"
				  << " constructed as a regular bubble type" << std::endl;
	}
	else
	{
		m_bubbleType = bubbleType;
		LoadBubbleMedia(m_gRenderer);
	}
}


cRegularBubble::~cRegularBubble()
{
}

void cRegularBubble::DisplayPopAnimation()
{
}


