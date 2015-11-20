//Ryan Bell

/*
* CLASS NOT YET IMPALAMENTED (PLACE HOLDER)
*/
#include "cBubblePhysics.h"

cBubblePhysics::cBubblePhysics() : m_xMovemenet(0), m_yMovement(0), m_shotAtDegree(0), m_xPixelCount(0), m_bubbleReachedEnd(false)
{

}

cBubblePhysics::~cBubblePhysics()
{

}

void cBubblePhysics::CalculateVector()
{
	m_xMovemenet = cos(m_shotAtDegree*(PI / AREAOFTRIANGLE)) * PIXELS_TO_MOVE_BUBBLE_PERSECOND;
	m_yMovement = sin(m_shotAtDegree * (PI / AREAOFTRIANGLE)) * PIXELS_TO_MOVE_BUBBLE_PERSECOND;
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

