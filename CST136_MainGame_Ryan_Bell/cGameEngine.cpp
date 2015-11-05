//!+++ Ryan Bell - cGameEngine.cpp

#include "cGameEngine.h"
#include <iostream>    // For demonstration purposes

const int FIRED_BUBBLE_Y = 10; // Bubble going to be fired location
const int FIRED_BUBBLE_X = 7; // Bubble going to be fired location

cGameEngine::cGameEngine()
{
	//  Dynamically allocate space in a ragged array
	for (int i = 0; i < NUM_OF_ROWS_Y; i++) //  i is used as indexing variable
	{
		if (i % 2 == 0) //  Check if row number is even or odd
		{
			m_bubbleArray[i] = new cBubble*[NUM_BUBBLES_EVEN]();
		}
		else
		{
			m_bubbleArray[i] = new cBubble*[NUM_BUBBLES_ODD]();
		}
	}
}

cGameEngine::~cGameEngine()
{
	int rowLength; //  Integer to store if row is even or odd
	for (int y = 0; y < NUM_OF_ROWS_Y; y++)
	{
		if (y % 2 == 0) //  Check if row is even or odd
		{
			rowLength = NUM_BUBBLES_EVEN;
		}
		else
		{
			rowLength = NUM_BUBBLES_ODD;
		}

		for (int xIndex = 0; xIndex < rowLength; xIndex++)
			//  For length of current row deallocate any allocated cBubbles
		{
			std::cout << "DEALLOCATING BUBBLE MEMORY [" << y << "][" << xIndex << "]\n"; //  For demonstration purposes
			delete m_bubbleArray[y][xIndex];
			m_bubbleArray[y][xIndex] = nullptr;

			m_gameRender.DisplayCurrentPlayFeild(m_bubbleArray);
			//  For demonstration purposes
			SDL_Delay(50);
			//  For demonstration purposes
		}
		delete[] m_bubbleArray[y];
		m_bubbleArray[y] = nullptr;
	}
}

void cGameEngine::BeginGame()
{
	const int STARING_ROW_NUM = 3;
	//  How many rows the game begins with
	const int ARRAY_PIXEL_LOCATION_X = 430;
	// X-Loacation of the start of bubble array (in pixels)
	const int ARRAY_PIXEL_LOCATION_y = 80;
	// Y-Location of the start of the bubble array (in pixels)

	for (int y = 0; y < STARING_ROW_NUM; y++)
	{
		// Calculate how many bubbles belong in that row
		if (y % 2 == 0)
		{
			for (int x = 0; x < NUM_BUBBLES_EVEN; x++)
			{
				m_bubbleArray[y][x] = new cBubble;
				// Fill first few rows with randomly colored
				// bubbles (As called by the default c'tor)
				m_bubbleArray[y][x]->SetDestinationRect((SINGLE_BUBBLE_W * x)
					+ ARRAY_PIXEL_LOCATION_X, (SINGLE_BUBBLE_H * y)
					+ ARRAY_PIXEL_LOCATION_y);
				// Set pixel location for bubble
				// based on previous bubbles location
			}
		}
		else
		{
			for (int x = 0; x < NUM_BUBBLES_ODD; x++)
			{
				m_bubbleArray[y][x] = new cBubble;
				// Fill first few rows with randomly
				// colored bubbles (As called by the default c'tor)
				m_bubbleArray[y][x]->SetDestinationRect(((SINGLE_BUBBLE_W * x)
					+ (ARRAY_PIXEL_LOCATION_X)+(SINGLE_BUBBLE_W / 2)),
					(SINGLE_BUBBLE_H * y) + ARRAY_PIXEL_LOCATION_y);
				// Set pixel location for bubble based on previous
				// bubbles location (additional staggering of half
				// a bubble added to odd rows)
			}
		}
	}

	m_bubbleArray[FIRED_BUBBLE_Y][FIRED_BUBBLE_X] = new cBubble;
	// Bubble going to be shot
	m_gameRender.DisplayCurrentPlayFeild(m_bubbleArray);
	//  Display Current play field (based on updated bubble array)
}

void cGameEngine::RunGameLoop()
{
	SDL_Event eventStream;	// SDL event handler
	cArrow tempArrow;		// temporary arrow object to hold default position

	bool quit = false;	// Condition flag set true if the user closes the
						// game window or(for demonstration purposes)
						// if the user presses spacebar

	while (!quit)
	{
		cBubble tempRandBubble;

		while (SDL_PollEvent(&eventStream) != 0)
			// If SDL is still polling a continuous/repeated event
		{
			if (eventStream.type == SDL_QUIT)
			{
				quit = true;		    // User has selected to close the window
			}
			else if (eventStream.type == SDL_KEYDOWN)
			{
				switch (eventStream.key.keysym.sym)
				{
				case SDLK_LEFT:
					m_gameRender.GetArrowObject().SetArrowRect(LEFT);
					// Moves arrow object's source rectangle over to
					// the left by the width of one arrow
					break;
				case SDLK_RIGHT:
					m_gameRender.GetArrowObject().SetArrowRect(RIGHT);
					// Moves arrow object's source rectangle
					// over to the right by the width of one arrow
					break;
				case SDLK_UP:
					// Reset arrow to upward(0 degree) tilt
					m_gameRender.GetArrowObject() = tempArrow;
					break;
				case SDLK_DOWN:
					// Pick a different color bubble to fire
					*m_bubbleArray[FIRED_BUBBLE_Y]
						[FIRED_BUBBLE_X] = tempRandBubble;
					break;
				case SDLK_SPACE: // For when the firing mechanism is implemented
					quit = true;
					// To demonstrate deleting of objects
					// either press space or close window
					break;
				}
			}

			m_gameRender.DisplayCurrentPlayFeild(m_bubbleArray);
			// Display updated game board
		}
	}
}