//Ryan Bell

#ifndef CSTATICBUBBLE
#define CSTATICBUBBLE_H
#include "cBubble.h"

class cStaticBubble : public cBubble
{
public:
	cStaticBubble(SDL_Renderer * m_gRenderer);
	~cStaticBubble();

	void IncreaseTouching(cBubble ** bubbleArray[],
												  SDL_Renderer * m_gRenderer);
	void DisplayPopAnimation();
};
#endif
