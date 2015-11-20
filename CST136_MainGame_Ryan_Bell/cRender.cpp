//Ryan Bell

#include "cRender.h"
#include <iostream>
#include <time.h>	//Used for sRand
#include <SDL_image.h>

using std::cout;	// Error checking purposes
using std::endl;

cRender::cRender() : m_shooterArrow(nullptr), 
					 m_gWindow(nullptr), 
					 m_gRenderer(nullptr), 
					 m_gTextures{}, 
					 m_bubbleArray{},
					 m_firedBubble(nullptr),
					 m_frameCount(0),
					 m_userFiredABubble(false)// Base memeber initalize to values
{
	if (Initalize() == false) // Call initalize function
	{
		cout << "An error occurred in initializing the renderer" << endl;
	}
	if (LoadMedia() == false)	// Call load media Function
	{
		cout << "An error occurred in trying to load the background Media" 
			 << endl;
	}

	int oddOrEven = 0; // Integer telling weather row is odd or even
	for (int rowNumber = 0; rowNumber < BUBBLE_ARRAY_ROWS_Y; rowNumber++)		
		// Dynamically allocate space for every possible location of a bubble
	{
		if (rowNumber % 2 == 0)					// Check if Row is odd or even
		{
			m_bubbleArray[rowNumber] = new cBubble * [BUBBLE_ARRAY_EVEN_X];
			oddOrEven = BUBBLE_ARRAY_EVEN_X;
		}
		else
		{
			m_bubbleArray[rowNumber] = new cBubble * [BUBBLE_ARRAY_ODD_X];
			oddOrEven = BUBBLE_ARRAY_ODD_X;
		}

		for (int x = 0; x < oddOrEven; x++)
		{
			m_bubbleArray[rowNumber][x] = nullptr;// Initalize pointers to null
		}
	}
}

cRender::~cRender()
{
	int rowLength;	 //  Integer to store if row is even or odd
	for (int y = 0; y < BUBBLE_ARRAY_ROWS_Y; y++)
	{
		if (y % 2 == 0)		//  Check if row is even or odd
		{
			rowLength = BUBBLE_ARRAY_EVEN_X;
		}
		else
		{
			rowLength = BUBBLE_ARRAY_ODD_X;
		}

		for (int xIndex = 0; xIndex < rowLength; xIndex++)						
				//  For length of current row deallocate any allocated cBubbles
		{
			std::cout << "DEALLOCATING BUBBLE MEMORY [" 
					  << y << "][" << xIndex << "]\n";
						//  For demonstration purposes
			delete m_bubbleArray[y][xIndex];
			m_bubbleArray[y][xIndex] = nullptr;
		}

		delete[] m_bubbleArray[y];
		m_bubbleArray[y] = nullptr;
	}

	delete m_shooterArrow;	// Delte coposite arrow
	m_shooterArrow = nullptr; //Return pointers to null

	for (int i = 0; i < TOTAL_BACKGROUNDS; i++) // Delete all backgrounds
	{
		SDL_DestroyTexture(m_gTextures[i]);
		m_gTextures[i] = nullptr;
	}
		
	SDL_DestroyRenderer(m_gRenderer);		// Destroy Renderer
	SDL_DestroyWindow(m_gWindow);			// Destroy Window
	m_gWindow = nullptr;					// Set pointers to null
	m_gRenderer = nullptr;

	delete m_firedBubble;
	m_firedBubble = nullptr;

	IMG_Quit();	// Quit SDL subsystems
	SDL_Quit();
}

bool cRender::Initalize()
{
	srand(time(NULL)); // On initialization generate a random seed

	bool Intsuccess = true; 
		 // Success flag if everything is initialized correctly  Initialize SDL

	if (SDL_Init(SDL_INIT_VIDEO) < 0) // Intalize SDL_subsytems
	{
		cout << "SDL could not initialize! SDL Error: " 
			 << SDL_GetError() 
			 << endl;
		Intsuccess = false;
	}
	else
	{
		int imgFlags = IMG_INIT_PNG;

		if (!(IMG_Init(imgFlags) & imgFlags))
		{
			cout << "SDL_image could not initialize! SDL_image Error: "
					<<IMG_GetError()
					<<endl;
			Intsuccess = false;
		}
		else
		{
			// Test for texture filtering is set to linear
			if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
			{
				cout << "Warning: Linear texture filtering not enabled!";
			}

			// Create Game window
			m_gWindow = SDL_CreateWindow(GAME_NAME, 
										SDL_WINDOWPOS_UNDEFINED, 
										SDL_WINDOWPOS_UNDEFINED,
										SCREEN_WIDTH, 
										SCREEN_HEIGHT, 
										SDL_WINDOW_SHOWN);
			if (m_gWindow == nullptr)
			{
				cout << "Window could not be created! SDL Error: " 
					 << SDL_GetError() 
					 << endl;
				Intsuccess = false;
			}
			else
			{
				// Create renderer for window
				m_gRenderer = SDL_CreateRenderer(m_gWindow, -1,
												SDL_RENDERER_ACCELERATED |
													SDL_RENDERER_PRESENTVSYNC);

				if (m_gRenderer == nullptr)
				{
					cout << "Renderer could not be created! SDL Error: "
						 << SDL_GetError() 
						 << endl;
					Intsuccess = false;
				}
			}
		}
	}
	// Set Render color
	SDL_SetRenderDrawColor(m_gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	return Intsuccess;
}

bool cRender::LoadMedia()
{
	m_shooterArrow = new cArrow(m_gRenderer);
	bool mediaSuccess = true;
	// Success flag set for loading media into textures

	SDL_Surface* tempSurface = nullptr;											
	// Temporary surface to be used before converted to a texture

	for (int i = 0; i < TOTAL_BACKGROUNDS && mediaSuccess == true; i++)			
		// For each image that needs to be loaded
	{
		tempSurface = IMG_Load(BACKGROUND_IMAGE_PATH[i]);						
		// Load BMP image onto a surface

		if (tempSurface == nullptr)
		{
			cout << "Unable to load image" 
				<< BACKGROUND_IMAGE_PATH[i] 
				<< "! SDL_image Error: "
				<< SDL_GetError()
				<< endl;

			mediaSuccess = false;
		}
		else
		{
			m_gTextures[i] = SDL_CreateTextureFromSurface(m_gRenderer,
																  tempSurface);
			if (m_gTextures[i] == nullptr)										
			// Create texture from surface
			{
				cout << "Unable to create texture from" 
					<< BACKGROUND_IMAGE_PATH[i] 
					<< "! SDL Error: " 
					<< SDL_GetError() 
					<< endl;

				mediaSuccess = false;
			}
		}
	}

	SDL_FreeSurface(tempSurface);												
		// Free temporary surface (all media are now textures)

	return mediaSuccess;
}

void cRender::DisplayCurrentPlayField()
{
	

	SDL_RenderClear(m_gRenderer); // Clear current rendering surface (cleared to all white)

	SDL_RenderCopy(m_gRenderer, m_gTextures[BACKSPASH], NULL, NULL); // Render Backsplash
	SDL_RenderCopy(m_gRenderer, m_gTextures[BACKGROUND], NULL, NULL); // Render Background

	int xLength; // integer to hold whether row is even or odd
	for (int y = 0; y < BUBBLE_ARRAY_ROWS_Y; y++)
	{
		if (y % 2 == 0)	// Determine if the row is odd or even
		{
			xLength = BUBBLE_ARRAY_EVEN_X;
		}
		else
		{
			xLength = BUBBLE_ARRAY_ODD_X;
		}

		for (int x = 0; x < xLength; x++)// Display all the bubbles in that row
		{
			if (m_bubbleArray[y][x] != nullptr)
			{
				m_bubbleArray[y][x]->RenderBubble(m_gRenderer);
			}	
		}
	}
	m_shooterArrow->RenderArrow(m_gRenderer); // Render arrow to scrren

	if (m_userFiredABubble == true)
	{
		m_firedBubble->CalcualteBubbleVector(m_shooterArrow->m_degreesRotation);
	}

	m_firedBubble->RenderBubble(m_gRenderer); // Render fire Bubble to screen
	SDL_RenderPresent(m_gRenderer);	// Update screen
	m_frameCount++;
	
}

cBubble *** cRender::GetBubbleArray()
{
	return m_bubbleArray; // return pointer to bubbleArray
}

 SDL_Renderer * cRender::GetRenderer() 
{
	return m_gRenderer;	// Return render by vlaue (so it may be modified)
}

 void cRender::SetFiredBuble(cBubble * bubleToSet)
 {
	 m_firedBubble = bubleToSet;	// copy passed bubble 
	 m_firedBubble->SetBubbleDestinationRectangle(FIRED_BUBBLE_X, 
												  FIRED_BUBBLE_Y);
	 
	 bubleToSet = nullptr;
 }

 void cRender::SetArrowPosition(const Direction & moveDirection)
 {
	 {
		 if (moveDirection == LEFT && 
			  (m_shooterArrow->m_degreesRotation - ARROW_ROTATION_INCRAMENT) >
														     -MAX_ARROW_DEGREE)
		 {
			 m_shooterArrow->m_degreesRotation -= ARROW_ROTATION_INCRAMENT;
			 //Decrease tilt of arrow if possible
		 }
		 else if(moveDirection == RIGHT && 
					m_shooterArrow->m_degreesRotation +
								   ARROW_ROTATION_INCRAMENT < MAX_ARROW_DEGREE)
		 {
			 //Increase tilit if possible
			 m_shooterArrow->m_degreesRotation += ARROW_ROTATION_INCRAMENT;
		 }
		 else if (moveDirection == DEFAULT)
		 {
			 //Set to zero if up-arrow is pressed
			 m_shooterArrow->m_degreesRotation = 0;
		 }
	 }
 }

 

