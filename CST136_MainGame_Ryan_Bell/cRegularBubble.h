//Ryan Bell

#ifndef CREGULARBUBBLE_H
#define CREGULARBUBBLE_H
#include"cBubble.h"

class cRegularBubble :public cBubble 
{
public:
	cRegularBubble(SDL_Renderer * m_gRenderer);
	cRegularBubble(SDL_Renderer * m_gRenderer, BUBBLE_TYPE bubbleType);
	~cRegularBubble();

	void DisplayPopAnimation();
};
#endif
