//Ryan Bell

#ifndef CFIREBUBBLE_H
#define CFIREBUBBLE_H
#include "cBubble.h"
#include <iostream>

class cFirePopBubble : public cBubble
{

public:
	cFirePopBubble(SDL_Renderer * m_gRenderer);
	~cFirePopBubble();

	void DisplayPopAnimation();
	void SpecialEffect(cBubble ** bubbleArray[], SDL_Renderer * m_gRenderer);
};
#endif

