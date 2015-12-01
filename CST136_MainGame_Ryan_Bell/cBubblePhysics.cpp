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

bool cBubblePhysics::CheckVector(int x, int y, cBubble** bubbleArray[])
{
	// Initial checks for bubble colliding with the walls/ ceiling
	bool recalculatedVector = false;
	if (x < LEFT_EDGE_PLAYFEILD || x > RIGHT_EDGE_PLAYFEILD)
	{
		m_shotAtDegree = AREAOFTRIANGLE - m_shotAtDegree;
		CalculateVector();
		recalculatedVector = true;
	}

	int oddOrEven = 0;
	int pxlOffsetPerRow = BUBBLE_PXL_BOARDER_SPACING - BUBBLE_PXL_OFFSET_ODD_Y;	// Start offset at 24 to account for boarder and account for adding unneeded offset in the first iteration
	int pxlOffsetPerElement = 0;
	int pxlOffsetOfCurrentElement = 0;

	for (int row = 0; row < BUBBLE_ARRAY_ROWS_Y; row++)
	{
		if (row % 2 == 0)									// Check if current row is even or odd
		{
			oddOrEven = BUBBLE_ARRAY_EVEN_X;
			pxlOffsetPerRow += BUBBLE_PXL_OFFSET_ODD_Y;		// Add the previous rows offset
			pxlOffsetPerElement = BUBBLE_PXL_OFFSET_EVEN_X;	// change pxl offset to account for current row
		}
		else												// check if Current row is odd
		{
			oddOrEven = BUBBLE_ARRAY_ODD_X;
			pxlOffsetPerRow += BUBBLE_PXL_OFFSET_EVEN_Y;	// Add the previous rows offset
			pxlOffsetPerElement = BUBBLE_PXL_OFFSET_ODD_X;	// change pxl offset to account for current row
		}

		for (int element = 0; element < oddOrEven; element++)
		{
			if (bubbleArray[row][element] != nullptr)
			{
				pxlOffsetOfCurrentElement = pxlOffsetPerElement + (SINGLE_BUBBLE_SIZE * element);
				if ((x <= pxlOffsetOfCurrentElement + SINGLE_BUBBLE_SIZE && x >= pxlOffsetOfCurrentElement) && ( y >= pxlOffsetPerRow-(SINGLE_BUBBLE_SIZE) && y <= pxlOffsetPerRow + SINGLE_BUBBLE_SIZE))
				{
					m_xPixelCount = element;
					m_yPixelCount = row;
					m_bubbleReachedEnd = true;				// collision detected
				}
			}
		}
	}

	if (m_bubbleReachedEnd != true && y <= BUBBLE_PXL_BOARDER_SPACING)
	{
		for (int lastElements = 0; lastElements < BUBBLE_ARRAY_EVEN_X; lastElements)
		{
			if (bubbleArray[0][lastElements] == nullptr && (x >= BUBBLE_PXL_OFFSET_EVEN_X + (SINGLE_BUBBLE_SIZE * lastElements) && x <= BUBBLE_PXL_OFFSET_EVEN_X + SINGLE_BUBBLE_SIZE + (SINGLE_BUBBLE_SIZE*lastElements)))
			{
				m_yPixelCount = -1;
				m_xPixelCount = lastElements;
			}
		}
	}
	
	return recalculatedVector;
}

