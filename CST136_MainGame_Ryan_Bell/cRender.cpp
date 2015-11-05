//!+++ Ryan Bell - cRender.cpp

#include "cRender.h"
#include <iostream>
#include <time.h> // For generating a random seed

using std::cout;
using std::endl;

cRender::cRender() : m_gWindow(nullptr), m_gRenderer(nullptr)
{
	if (Initalize() == false || LoadMedia() == false)
		// Intalize textures and load media
	{
		cout << endl << "Failed to load renderer object" << endl;
	}
}

cRender::~cRender()
{
	for (int i = 0; i < totalTextures; i++) // Destroy any allocated textures
	{
		SDL_DestroyTexture(m_gTextures[i]);
		m_gTextures[i] = nullptr;
	}

	SDL_DestroyRenderer(m_gRenderer);	// Destroy Renderer
	SDL_DestroyWindow(m_gWindow);		// Destroy window
	m_gWindow = nullptr;				// Set pointers back to null
	m_gRenderer = nullptr;

	SDL_Quit();							// Quit SDL subsystems
}

cArrow& cRender::GetArrowObject()
{
	return m_arrow;				// Return a reference to m_arrow
}

bool cRender::Initalize()
{
	char* const GAME_NAME = "Techno Bubble Puzzle";	// Name of the game
	const int SCREEN_WIDTH = 1658; // Screen Size -width (in pixels)
	const int SCREEN_HEIGHT = 847; // Screen Size - height (in pixels)

	srand(time(NULL)); // On initialization generate a random seed

	bool Intsuccess = true;
	// Success flag if everything is initalized correctly
	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL could not initialize! SDL Error: "
			<< SDL_GetError() << endl;
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
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);

		if (m_gWindow == nullptr)
		{
			cout << "Window could not be created! SDL Error: "
				<< SDL_GetError() << endl;

			Intsuccess = false;
		}
		else
		{
			// Create renderer for window
			m_gRenderer = SDL_CreateRenderer(m_gWindow, -1,
				SDL_RENDERER_ACCELERATED);

			if (m_gRenderer == nullptr)
			{
				cout << "Renderer could not be created! SDL Error: "
					<< SDL_GetError() << endl;
				Intsuccess = false;
			}
		}
	}

	return Intsuccess;
	// Return success flag (will be false if an error occurred)
}

bool cRender::LoadMedia()
{
	char* const texturePath[] = { "BackSplashYellow.bmp", "Bubbles.bmp", "DirectionArrow.bmp" }; // BMP image paths

	bool mediaSuccess = true;	// Success flag set for loading media into textures

	SDL_Surface* tempSurface = nullptr;	// Temporary surface to be used before converted to a texture

	for (int i = 0; i < totalTextures && mediaSuccess == true; i++)		// For each image that needs to be loaded
	{
		tempSurface = SDL_LoadBMP(texturePath[i]);					// Load BMP image onto a surface
		if (tempSurface == nullptr)
		{
			cout << "Unable to load image" << texturePath[i] << "! SDL_image Error: " << SDL_GetError() << endl;

			mediaSuccess = false;
		}
		else
		{
			m_gTextures[i] = SDL_CreateTextureFromSurface(m_gRenderer,
				tempSurface);
			// Create texture from surface
			if (m_gTextures[i] == nullptr)
			{
				cout << "Unable to create texture from"
					<< texturePath[i]
					<< "! SDL Error: "
					<< SDL_GetError() << endl;

				mediaSuccess = false;
			}
		}
	}

	SDL_FreeSurface(tempSurface);	// Free temporary surface
									// (all media are now textures)

	return mediaSuccess;	// Return success flag
							// (will be false if a img did not load correctly)
}

void cRender::DisplayCurrentPlayFeild(cBubble ** bubbleArray[])
{
	SDL_RenderClear(m_gRenderer);
	// Clear current rendering surface (cleared to all white)

	SDL_RenderCopy(m_gRenderer, m_gTextures[PLAYFIELD], NULL, NULL);
	// Render Background
	SDL_RenderCopy(m_gRenderer, m_gTextures[DIRECTIONARROWS],
		&m_arrow.GetArrowSrcRect(),
		&m_arrow.GetArrowDestRect()); // Render current arrow

	int xLength; // integer to hold weather row is even or odd
	for (int y = 0; y < NUM_OF_ROWS_Y; y++)
	{
		// Determine if the row is odd or even
		if (y % 2 == 0)
		{
			xLength = NUM_BUBBLES_EVEN;
		}
		else
		{
			xLength = NUM_BUBBLES_ODD;
		}
		// Display all the bubbles in that row
		for (int x = 0; x < xLength; x++)
		{
			if (bubbleArray[y] != nullptr) // This check is for demonstration
										   // purposes[called in destructor]
										   // (normally you would not be
										   // displaying function with a null
										   // parts of the bubble array)
			{
				if (bubbleArray[y][x] != nullptr)
				{
					SDL_RenderCopy(m_gRenderer, m_gTextures[BUBBLEIMG],
						&bubbleArray[y][x]->GetSourceRect(),
						&bubbleArray[y][x]->GetDestinationRect());
				}
			}
		}
	}

	SDL_RenderPresent(m_gRenderer);	// Update screen
}