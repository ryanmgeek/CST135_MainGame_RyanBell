//!+++  Ryan Bell - cBubble.cpp

#include "cBubble.h"
#include <iostream>

using std::cout;
using std::endl;

cBubble::cBubble() : m_touchingBubblesCount(0), m_bubbleColor(BLACK)
{
	//  Seed for rand() is determined in the cRender.itialize() method
	m_bubbleColor = static_cast<bubbleColor>(rand() % TOTALBUBBLES);
	//  Choose random color for a default constructed bubble

	m_sourceRect.x = SINGLE_BUBBLE_W * m_bubbleColor;
	m_sourceRect.y = 0; //  Don't offset y coordinate
	m_sourceRect.w = SINGLE_BUBBLE_W;
	m_sourceRect.h = SINGLE_BUBBLE_H;

	m_destinationRect.x = 0;
	m_destinationRect.y = 0;
	m_destinationRect.w = SINGLE_BUBBLE_W;
	m_destinationRect.h = SINGLE_BUBBLE_H;
}

cBubble::cBubble(bubbleColor passedColor)
	: m_touchingBubblesCount(0), m_bubbleColor(passedColor)
{
	m_sourceRect.x = SINGLE_BUBBLE_W * m_bubbleColor;
	m_sourceRect.y = 0; //  Don't offset y coordinate
	m_sourceRect.w = SINGLE_BUBBLE_W;
	m_sourceRect.h = SINGLE_BUBBLE_H;

	m_destinationRect.x = 0;
	m_destinationRect.y = 0;
	m_destinationRect.w = SINGLE_BUBBLE_W;
	m_destinationRect.h = SINGLE_BUBBLE_H;
}

cBubble::~cBubble()
{
}

cBubble & cBubble::operator=(const cBubble &rightSide)
{
	if (this != &rightSide) //  if A=A check
	{
		m_sourceRect = rightSide.m_sourceRect;
		m_destinationRect = rightSide.m_destinationRect;
		m_bubbleColor = rightSide.m_bubbleColor;
		m_touchingBubblesCount = rightSide.m_touchingBubblesCount;
	}
	return *this;
}

cBubble::cBubble(const cBubble & rightSide)
{
	m_sourceRect = rightSide.m_sourceRect;
	m_destinationRect = rightSide.m_destinationRect;
	m_bubbleColor = rightSide.m_bubbleColor;
	m_touchingBubblesCount = rightSide.m_touchingBubblesCount;
}

void cBubble::IncreaseTouching(int passedIncreaseAmount)
{
	if (passedIncreaseAmount > 0) //  Check to see if touching
								  //  increase amount is logical
	{
		m_touchingBubblesCount += passedIncreaseAmount;
	}
	else
	{
		cout << "Could not increment a bubbles count by " << passedIncreaseAmount << " Not a valid number!" << endl;
	}
}

int cBubble::GetTouchingCount()
{
	return m_touchingBubblesCount;
}

const SDL_Rect & cBubble::GetSourceRect() const
{
	return m_sourceRect;
}

const SDL_Rect & cBubble::GetDestinationRect() const
{
	return m_destinationRect;
}

void cBubble::SetDestinationRect(int xCordPx, int yCordPx)
{
	if (xCordPx >= 0 && yCordPx >= 0) //  Check passed cordiantes
	{
		m_destinationRect.x = xCordPx;
		m_destinationRect.y = yCordPx;
	}
	else
	{
		cout << "Could Not set the destination of this bubble object to "
			<< xCordPx << " , " << yCordPx << endl;
	}
}