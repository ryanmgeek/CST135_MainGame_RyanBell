//Ryan Bell

#ifndef CRANDOMCOLORBUBBLE_H
#define CRANDOMCOLORBUBBLE_H
#include "cBubble.h"

class cRandomColorBubble : public cBubble
{
public:
	cRandomColorBubble(SDL_Renderer * m_gRenderer);
	~cRandomColorBubble();

	void DisplayPopAnimation();
	void SpecialEffect(cBubble ** bubbleArray[], SDL_Renderer * m_gRenderer);
};

#endif
