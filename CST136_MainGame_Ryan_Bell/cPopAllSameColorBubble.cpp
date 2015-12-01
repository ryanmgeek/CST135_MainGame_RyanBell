//Ryan Bell

#include "cPopAllSameColorBubble.h"

cPopAllSameColorBubble::cPopAllSameColorBubble(SDL_Renderer * m_gRenderer)
{
	//generate a random color fo the Pop bubble type
	m_bubbleType = static_cast<BUBBLE_TYPE>((rand() % (WHITE + 1)) + RED_POP);
	LoadBubbleMedia(m_gRenderer);
}

cPopAllSameColorBubble::cPopAllSameColorBubble(SDL_Renderer * m_gRenderer, 
														BUBBLE_TYPE bubbleType)
{
	if (bubbleType < RED_POP || bubbleType > WHITE_POP)
	{
		std::cout << "A invalid bubble type was attempted to"
				  << " be constructed as a \"POP bubble type\"" 
				  << std::endl;
	}
	else
	{
		m_bubbleType = bubbleType;
		LoadBubbleMedia(m_gRenderer);
	}
}

cPopAllSameColorBubble::~cPopAllSameColorBubble()
{
}

void cPopAllSameColorBubble::DisplayPopAnimation()
{
}

void cPopAllSameColorBubble::SpecialEffect(cBubble ** bubbleArray[],
											        SDL_Renderer * m_gRenderer)
{
}
