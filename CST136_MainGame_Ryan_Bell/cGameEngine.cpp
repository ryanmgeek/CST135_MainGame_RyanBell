//Ryan Bell

#include "cGameEngine.h"
#include <iostream>

// Include All Bubble Types 
#include "cRegularBubble.h"
#include "cFirePopBubble.h"
#include "cMatchColorBubble.h"
#include "cPopAllSameColorBubble.h"
#include "cRandomColorBubble.h"
#include "cStaticBubble.h"

cGameEngine::cGameEngine() : m_gameRender(new cRender)
{
	m_gameRender->SetFiredBuble(GenerateBubble());
	// Set the firing bubble to a random generated type
}

cGameEngine::~cGameEngine()
{
	delete m_gameRender;
}

void cGameEngine::BeginGame()
{
	int randomBubble = 0;
	int evenOrOdd = 0;
	int pixelsDownOffSet = BUBBLE_PXL_BOARDER_SPACING; // account for boarder

	for (int y = 0; y < NUMBER_OF_START_ROWS; y++)
	{
		if (y % 2 == 0) // Check if current row is odd
		{
			evenOrOdd = BUBBLE_ARRAY_EVEN_X;
		}
		else
		{
			evenOrOdd = BUBBLE_ARRAY_ODD_X;
		}

		for (int x = 0; x < evenOrOdd; x++)
		{
			m_gameRender->m_bubbleArray[y][x] = GenerateBubble();
			// Fill current array location with a new bubble

			if (evenOrOdd == BUBBLE_ARRAY_EVEN_X)
			{ // set the new bubbles corinates based on current element 
				m_gameRender->m_bubbleArray[y][x]->
					SetBubbleDestinationRectangle(
						(x* SINGLE_BUBBLE_SIZE) +
						BUBBLE_PXL_OFFSET_EVEN_X,
						pixelsDownOffSet);
			}
			else
			{ // set the new bubbles cordinates based on current element
				m_gameRender->m_bubbleArray[y][x]->
					SetBubbleDestinationRectangle(
						(x* SINGLE_BUBBLE_SIZE) +
						BUBBLE_PXL_OFFSET_ODD_X,
						pixelsDownOffSet);
			}
			m_gameRender->m_bubbleArray[y][x]->SetArrayLocations(y, x);
		}

		if (evenOrOdd == BUBBLE_ARRAY_EVEN_X)
		{
			pixelsDownOffSet += BUBBLE_PXL_OFFSET_ODD_Y;
			// Add additional pixel offset
		}
		else
		{
			pixelsDownOffSet += BUBBLE_PXL_OFFSET_EVEN_Y;
			// Add additional pixel offset
		}
	}
}

void cGameEngine::RunGame()
{
	SDL_Event eventStream;	// SDL event handler
	bool quit = false;		// Condition flag set true if the user closes 
							// the game window or(for demonstration purposes)
							// if the user presses spacebar

	while (!quit)
	{
		while (SDL_PollEvent(&eventStream) != 0)
			// If SDL is still polling a continuous/repeated event
		{
			if (eventStream.type == SDL_QUIT)
			{
				quit = true;		// User has selected to close the window
			}
			else if (eventStream.type == SDL_KEYDOWN)
			{
				switch (eventStream.key.keysym.sym)
				{
				case SDLK_LEFT:
					m_gameRender->SetArrowPosition(LEFT);
					break;
				case SDLK_RIGHT:
					m_gameRender->SetArrowPosition(RIGHT);
					break;
				case SDLK_UP:
					m_gameRender->SetArrowPosition(DEFAULT);
					break;
				case SDLK_RCTRL:
					HackGame();
					break;
				case SDLK_DOWN:
					GetNewBubble();
					m_gameRender->m_userFiredABubble = false;
					break;
				case SDLK_SPACE:
					m_gameRender->m_userFiredABubble = true;
					break;
				case SDLK_ESCAPE:
					quit = true;
					break;
				}
			}

			//m_gameRender->DisplayCurrentPlayField();
			// Display updated game board
		}
		m_gameRender->DisplayCurrentPlayField();
	}
}

void cGameEngine::GetNewBubble()
{
	delete m_gameRender->m_firedBubble;
	m_gameRender->SetFiredBuble(GenerateBubble());
	// Regerate current bubble to some other type
}

void cGameEngine::HackGame()
{
	// Cheat and change top row of bubbles randomly 
	int x = rand() % BUBBLE_ARRAY_EVEN_X; // Genrate number from 0-8
	delete m_gameRender->m_bubbleArray[0][x];	// Delete current bubble
												// generate a random bubble 
	m_gameRender->m_bubbleArray[0][x] = static_cast<cBubble*> (new cRegularBubble(m_gameRender->m_gRenderer));
	m_gameRender->m_bubbleArray[0][x]->SetBubbleDestinationRectangle(BUBBLE_PXL_OFFSET_EVEN_X + (x * SINGLE_BUBBLE_SIZE), BUBBLE_PXL_BOARDER_SPACING); // Set destination of new bubble
}

cBubble * cGameEngine::GenerateBubble()
{
	cBubble * returnBubble = nullptr;
	int randomBubble = static_cast<BUBBLE_TYPE>(rand() % TOTALBUBBLES);
	// Based on random number genrate a new bubble of the corsiponding type
	if (randomBubble >= RED && randomBubble <= WHITE)
	{
		returnBubble = new cRegularBubble(m_gameRender->GetRenderer());
	}
	else if (randomBubble >= RED_EQUAL && randomBubble <= WHITE_EQUAL)
	{
		returnBubble = new cMatchColorBubble(m_gameRender->GetRenderer());
	}
	else if (randomBubble >= RED_POP && randomBubble <= WHITE_POP)
	{
		returnBubble = new cPopAllSameColorBubble(m_gameRender->GetRenderer());
	}
	else if (randomBubble >= FIRE && randomBubble <= STATIC)
	{
		if (randomBubble == FIRE)
			returnBubble = new  cFirePopBubble(m_gameRender->GetRenderer());
		else if (randomBubble == RANDOMRECOLOR)
			returnBubble = new  cRandomColorBubble(m_gameRender->GetRenderer());
		else if (randomBubble == STATIC)
			returnBubble = new  cStaticBubble(m_gameRender->GetRenderer());
	}
	else
	{
		// ERROR checking
		std::cout << "Random bubble type generation not accounted for ERROR!"
			<< std::endl;
	}

	return returnBubble;
}
