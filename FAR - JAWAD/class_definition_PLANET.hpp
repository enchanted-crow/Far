void PLANET::PInit(int X, int Y, int R, int M)
{
	PTexture = NULL;

	PCenterX = X;
	PCenterY = Y;
	PRadius = R;
	PMass = M;

	PAxisX = PCenterX - PRadius;
	PAxisY = PCenterY - PRadius;

	PDestinationRect.x = PAxisX;
	PDestinationRect.y = PAxisY;
	PDestinationRect.w = 2 * PRadius;
	PDestinationRect.h = 2 * PRadius;
}

void PLANET::LoadPlanetTexture(std::string path)
{
	SDL_Surface *IntermidiateSurface = IMG_Load( path.c_str() );
	PTexture = SDL_CreateTextureFromSurface( gRenderer, IntermidiateSurface );
	SDL_FreeSurface(IntermidiateSurface);
}

void PLANET::render()
{
	// first NULL for rendering the entire texture..second Rect for rendering
	// in that particular position
	SDL_RenderCopy(gRenderer, PTexture, NULL, &PDestinationRect);
}

void PLANET::free()
{
	if(PTexture != NULL)
	{
		SDL_DestroyTexture(PTexture);
		PTexture = NULL;
	}
}