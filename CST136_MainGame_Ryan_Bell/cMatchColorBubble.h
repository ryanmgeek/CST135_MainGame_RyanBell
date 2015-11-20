//Ryan Bell

#ifndef CMATCHCOLORBUBBLE_H
#define MATCHCOLORBUBBLE_H
#include "cBubble.h"

class cMatchColorBubble : public cBubble
{
public:
	cMatchColorBubble(SDL_Renderer * m_gRenderer);
	cMatchColorBubble(SDL_Renderer * m_gRenderer, BUBBLE_TYPE bubbleType);
	~cMatchColorBubble();

	void DisplayPopAnimation();
	void SpecialEffect(cBubble ** bubbleArray[], SDL_Renderer * m_gRenderer);
};

#endif

