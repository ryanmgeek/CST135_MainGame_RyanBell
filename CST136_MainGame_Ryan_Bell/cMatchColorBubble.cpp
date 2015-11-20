//Ryan Bell

#include "cMatchColorBubble.h"

cMatchColorBubble::cMatchColorBubble(SDL_Renderer * m_gRenderer)
{
	// Genrate random color of equlas bubble type
	m_bubbleType = 
				static_cast<BUBBLE_TYPE>((rand() % (WHITE + 1)) +  RED_EQUAL);
	LoadBubbleMedia(m_gRenderer);
}

cMatchColorBubble::cMatchColorBubble(SDL_Renderer * m_gRenderer, BUBBLE_TYPE bubbleType)
{
	if (bubbleType < RED_EQUAL || bubbleType > WHITE_EQUAL)
	{
		std::cout << "A invalid bubble type was attempted"
				  <<" to be constructed as a \"MATCH COLOR bubble type\"" 
				  << std::endl;
	}
	else
	{
		m_bubbleType = bubbleType;
		LoadBubbleMedia(m_gRenderer);
	}
}

cMatchColorBubble::~cMatchColorBubble()
{
}

void cMatchColorBubble::DisplayPopAnimation()
{
}

void cMatchColorBubble::SpecialEffect(cBubble ** bubbleArray[],
												    SDL_Renderer * m_gRenderer)
{
}
