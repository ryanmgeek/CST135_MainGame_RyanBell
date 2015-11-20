//Ryan Bell

#ifndef CPOPALLSAMECOLORBUBBLE_H
#define CPOPALLSAMECOLORBUBBLE_H
#include "cBubble.h"

class cPopAllSameColorBubble : public cBubble
{
public:
	cPopAllSameColorBubble(SDL_Renderer * m_gRenderer);
	cPopAllSameColorBubble(SDL_Renderer * m_gRenderer, BUBBLE_TYPE bubbleType);
	~cPopAllSameColorBubble();

	void DisplayPopAnimation();
	void SpecialEffect(cBubble ** bubbleArray[], SDL_Renderer * m_gRenderer);
};

#endif