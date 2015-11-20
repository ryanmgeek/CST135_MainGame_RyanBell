//Ryan Bell

#include "cBubble.h"
#include <iostream>

cBubble::cBubble() : 
			m_physicsEngine(new cBubblePhysics), 
			m_sourceRectangle{0,0,SINGLE_BUBBLE_SIZE,SINGLE_BUBBLE_SIZE},
			m_destinationRectangle{0,0,SINGLE_BUBBLE_SIZE,SINGLE_BUBBLE_SIZE},
			m_bubbleTexture(nullptr),
			m_bubbleType(RED), 
			m_touchingBubbleCount(0)
			// Base memeber intalize all data memebers to default values 
{}

 cBubble::~cBubble()
{
	delete m_physicsEngine;			// Delete compsoite physics Engine
	m_physicsEngine = nullptr;		// Return pointer to null
	SDL_DestroyTexture(m_bubbleTexture);	// Destory Lingering textures
	m_bubbleTexture = nullptr;				// Return pointer to null
}

 cBubble & cBubble::operator=(const cBubble & rightSide) // Assignment overload
 {
	 if (this != &rightSide) //  if A=A check
	 {
		 m_touchingBubbleCount = rightSide.m_touchingBubbleCount;
		 m_bubbleType = rightSide.m_bubbleType;
		 m_sourceRectangle = rightSide.m_sourceRectangle;
		 m_destinationRectangle = rightSide.m_destinationRectangle;

		 delete m_physicsEngine;
		 m_physicsEngine = rightSide.m_physicsEngine;
		 SDL_DestroyTexture(m_bubbleTexture);
		 m_bubbleTexture = rightSide.m_bubbleTexture;
	 }
	 return *this;
 }

 cBubble::cBubble(const cBubble & rightSide)	// copy constructor
 {
	 m_touchingBubbleCount = rightSide.m_touchingBubbleCount;
	 m_bubbleType = rightSide.m_bubbleType;
	 m_sourceRectangle = rightSide.m_sourceRectangle;
	 m_destinationRectangle = rightSide.m_destinationRectangle;

	 delete m_physicsEngine;
	 m_physicsEngine = rightSide.m_physicsEngine;
	 SDL_DestroyTexture(m_bubbleTexture);
	 m_bubbleTexture = rightSide.m_bubbleTexture;
 }

void cBubble::RenderBubble(SDL_Renderer * m_gRenderer)
{
	SDL_RenderCopy(m_gRenderer,
					m_bubbleTexture,
					&m_sourceRectangle,
					&m_destinationRectangle);
					// Render current bubble to the screen	
}

void cBubble::SetBubbleDestinationRectangle(int const & xCordinate, 
											int const & yCordinate)
{
	if ((xCordinate >= 0 && yCordinate >= 0) && (xCordinate <= SCREEN_WIDTH-SINGLE_BUBBLE_SIZE && yCordinate <= SCREEN_HEIGHT-SINGLE_BUBBLE_SIZE)) //  Check passed coordinates
	{
		m_destinationRectangle.x = xCordinate;
		m_destinationRectangle.y = yCordinate;
	}
	else
	{
		std::cout << "Could Not set the destination of this bubble object to "
			<< xCordinate 
			<< " , " 
			<< yCordinate 
			<< std::endl;
	}
}


const int & cBubble::GetTouchingCount() const
{
	return m_touchingBubbleCount;	// Return copy of touch count
}

void cBubble::LoadBubbleMedia( SDL_Renderer * m_gRenderer)
{
	SDL_Surface * tempSurface = nullptr;	// Load image to temporary surface
	tempSurface = IMG_Load(BUBBLE_IMG_PATH);
	m_bubbleTexture = SDL_CreateTextureFromSurface(m_gRenderer, tempSurface);
	if (m_bubbleTexture == nullptr)
	{
		std::cout << "ERROR: The bubble surface could not be loaded" 
				  << std::endl;
	}
	SDL_FreeSurface(tempSurface);
								// Free surface after texture has been created

	m_destinationRectangle.w = 
		m_destinationRectangle.h = 
		m_sourceRectangle.w = 
		m_sourceRectangle.h = 
		SINGLE_BUBBLE_SIZE;	// Set rectangle width/ height the same

	int xCordinate = m_bubbleType;
	while (xCordinate - RED_EQUAL >= 0)	// Make x in the range of 0-5
	{
		xCordinate -= RED_EQUAL;
	}
	int yCordinate =  m_bubbleType / BUBBLEIMG_BUBBLES_PER_ROW;	
									// Make y correlate to a bubble row
	
	m_sourceRectangle.x = xCordinate * SINGLE_BUBBLE_SIZE;	
	m_sourceRectangle.y = yCordinate * SINGLE_BUBBLE_SIZE;

}

void cBubble::IncreaseTouching(cBubble ** bubbleArray[], 
								SDL_Renderer * m_gRenderer)
{
	//++ Depth First Search 
	// Note: not yet Implamaneted
	/*if (bubbleArray[0][0] != nullptr)
	{
		bubbleArray[0][0]->m_touchingBubbleCount = 0;
	}

	int evenOrOdd = 0;
	for (int i = RED; i < TOTALBUBBLES; i++)
	{
		for (int rowCount = 0; rowCount < BUBBLE_ARRAY_ROWS_Y; rowCount++)
		{
			if (rowCount % 2 == 0)
			{
				evenOrOdd = BUBBLE_ARRAY_EVEN_X;
			}
			else
			{
				evenOrOdd = BUBBLE_ARRAY_ODD_X;
			}
			for (int xElement; xElement < evenOrOdd; xElement++)
			{
				if (bubbleArray[rowCount][xElement-1] != nullptr)
				{
					return this; //first node
				}
			}

		}
	}*/

}

void cBubble::Pop(cBubble ** bubbleArray[], SDL_Renderer * m_gRenderer)
{
	// call pop animation function and destroy the bubble
}

void cBubble::SpecialEffect(cBubble ** bubbleArray[], 
													SDL_Renderer * m_gRenderer)
{
	// Display effect for when bubbles collide
}


void cBubble::CalcualteBubbleVector(const int & arrowDegrees)
{
	if (m_physicsEngine->m_bubbleReachedEnd != true)
	{
		int yIncreasePixel = 0; //calculate remained on the y cordinate
		m_physicsEngine->m_yPixelCount += (m_physicsEngine->m_yMovement - static_cast<int>(m_physicsEngine->m_yMovement));
		if (m_physicsEngine->m_yPixelCount >= 1)
		{
			m_physicsEngine->m_yPixelCount--;
			yIncreasePixel++;
		}
		int xIncreasePixel = 0;	//Calulate remaainder on the y cordinate
		m_physicsEngine->m_xPixelCount += (m_physicsEngine->m_xMovemenet - static_cast<int>(m_physicsEngine->m_xMovemenet));
		if (m_physicsEngine->m_xPixelCount >= 1)
		{
			m_physicsEngine->m_xPixelCount--;
			xIncreasePixel++;
		}

		//If this is the first call of the physics engine
		if (m_physicsEngine->m_xMovemenet == 0 && m_physicsEngine->m_yMovement == 0)
		{
			m_physicsEngine->m_shotAtDegree = RIGHTTRIANGLEANGLE - arrowDegrees;
			m_physicsEngine->CalculateVector();

			int  y = FIRED_BUBBLE_Y - m_physicsEngine->m_yMovement;
			int x = FIRED_BUBBLE_X + m_physicsEngine->m_xMovemenet;

			SetBubbleDestinationRectangle(x, y);
		}
		else
		{
			//If the vector has been calulcualted at least once
		}
		{
			int x = m_destinationRectangle.x + m_physicsEngine->m_xMovemenet + xIncreasePixel;
			int y = m_destinationRectangle.y - m_physicsEngine->m_yMovement - yIncreasePixel;

			bool recalculatedVector = m_physicsEngine->CheckVector(x, y);
			
			if (recalculatedVector == true)
			{
				x = m_destinationRectangle.x + m_physicsEngine->m_xMovemenet + xIncreasePixel;
				y = m_destinationRectangle.y - m_physicsEngine->m_yMovement - yIncreasePixel;
			}
			if (m_physicsEngine->m_bubbleReachedEnd != true)
			{
				SetBubbleDestinationRectangle(x, y);
			}
			else
			{
				SetBubbleDestinationRectangle(x, BUBBLE_PXL_BOARDER_SPACING);
			}
		}
	}
}

