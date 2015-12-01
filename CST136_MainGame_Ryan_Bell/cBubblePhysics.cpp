//Ryan Bell
#include "cBubblePhysics.h"

cBubblePhysics::cBubblePhysics() : m_xMovemenet(0), m_yMovement(0),
m_shotAtDegree(0), m_xPixelCount(0), m_bubbleReachedEnd(false)
{

}

cBubblePhysics::~cBubblePhysics()
{

}

cBubblePhysics::cBubblePhysics(const cBubblePhysics & rightSide)
{
	m_xMovemenet = rightSide.m_xMovemenet;
	m_yMovement = rightSide.m_yMovement;
	m_shotAtDegree = rightSide.m_shotAtDegree;
	m_yPixelCount = rightSide.m_yPixelCount;
	m_xPixelCount = rightSide.m_xPixelCount;
	m_bubbleReachedEnd = rightSide.m_bubbleReachedEnd;
}

cBubblePhysics & cBubblePhysics::operator=(const cBubblePhysics & rightSide)
{
	if (this != &rightSide)
	{
		m_xMovemenet = rightSide.m_xMovemenet;
		m_yMovement = rightSide.m_yMovement;
		m_shotAtDegree = rightSide.m_shotAtDegree;
		m_yPixelCount = rightSide.m_yPixelCount;
		m_xPixelCount = rightSide.m_xPixelCount;
		m_bubbleReachedEnd = rightSide.m_bubbleReachedEnd;
	}
	return *this;
}

void cBubblePhysics::CalculateVector()
{
	m_xMovemenet = cos(m_shotAtDegree*(PI / AREAOFTRIANGLE)) *
		PIXELS_TO_MOVE_BUBBLE_PERSECOND;
	m_yMovement = sin(m_shotAtDegree * (PI / AREAOFTRIANGLE)) *
		PIXELS_TO_MOVE_BUBBLE_PERSECOND;
}

bool cBubblePhysics::CheckVector(int x, int y)
{
	bool recalculatedVector = false;
	if (x < LEFT_EDGE_PLAYFEILD || x > RIGHT_EDGE_PLAYFEILD)
	{
		m_shotAtDegree = AREAOFTRIANGLE - m_shotAtDegree;
		CalculateVector();
		recalculatedVector = true;
	}
	if (y <= BUBBLE_PXL_BOARDER_SPACING)
	{
		m_bubbleReachedEnd = true;
	}
	return recalculatedVector;
}

