//Ryan Bell

#include "cArrow.h"
#include <iostream>	// ERROR reporting

cArrow::cArrow(SDL_Renderer * m_gRenderer) : m_arrowTexture(nullptr), 
										 	 m_destinationRectangle{},
											 m_degreesRotation(0),
											 m_rotationPoint{0,0}
{

	SDL_Surface * tempSurface = IMG_Load(ARROW_IMG_PATH); //Load arrow Img
	
	m_destinationRectangle.h = tempSurface->h; //get heigth from loaded surface
	m_destinationRectangle.w = tempSurface->w;
	m_arrowTexture = SDL_CreateTextureFromSurface(m_gRenderer, tempSurface);
	
	if (m_arrowTexture == nullptr) //Check surface was created correctly
	{
		std::cout << "ERROR: The arrow surface could not be loaded " 
				  << SDL_GetError() 
				  << std::endl;
	}

	SDL_FreeSurface(tempSurface); // Get rid of temporary surfcae
	tempSurface = nullptr;

	//Set defulat Destination rectangle values 
	m_destinationRectangle.x = (SCREEN_WIDTH - m_destinationRectangle.w) / 2;
	m_destinationRectangle.y = SCREEN_HEIGHT - m_destinationRectangle.h;

	m_rotationPoint.x = m_destinationRectangle.w / 2;
	m_rotationPoint.y = PIXEL_OFFSET_ROTATION;
}

cArrow::cArrow() : m_arrowTexture(nullptr), m_destinationRectangle{}
{
	std::cout << "An error occurred a arrow object has "
		      <<"been instantiated without being passed the renderer" 
		      << std::endl;
}

cArrow & cArrow::operator=(const cArrow & rightSide) //Assignment overload
{
	if (this != &rightSide)
	{
		SDL_DestroyTexture(m_arrowTexture);
		m_arrowTexture = rightSide.m_arrowTexture;
		m_degreesRotation = rightSide.m_degreesRotation;
		m_destinationRectangle = rightSide.m_destinationRectangle;
		m_rotationPoint = rightSide.m_rotationPoint;
	}
	return *this;
}

cArrow::cArrow(const cArrow & rightSide) //Copy constructor
{
	SDL_DestroyTexture(m_arrowTexture);
	m_arrowTexture = rightSide.m_arrowTexture;
	m_degreesRotation = rightSide.m_degreesRotation;
	m_destinationRectangle = rightSide.m_destinationRectangle;
	m_rotationPoint = rightSide.m_rotationPoint;
}

cArrow::~cArrow()
{
	SDL_DestroyTexture(m_arrowTexture); //Get rid of texture
	m_arrowTexture = nullptr;			//Return pointers to null
}

void cArrow::RenderArrow(SDL_Renderer * m_gRenderer)
{
	SDL_RenderCopyEx(m_gRenderer,
					 m_arrowTexture, 
					 nullptr, 
					 &m_destinationRectangle,
					 m_degreesRotation, 
					 &m_rotationPoint,
					 SDL_FLIP_NONE);
}

