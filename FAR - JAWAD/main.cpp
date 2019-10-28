#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <bits/stdc++.h>
using namespace std;

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 700;
const int NUMBER_OF_PLANETS = 2;
int flag = 1;

SDL_Texture* loadTexture(std::string path);

#include "classes_declaration.hpp"

bool init();
bool loadMedia();
void close();

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

LTexture gROCKETTexture;

SDL_Texture* BG = NULL;

PLANET planet[NUMBER_OF_PLANETS];

#include "classes_definition.hpp"
#include "user_defined_functions_definition.hpp"

int main( int argc, char* args[] )
{
	// SDL_Rect planetrect = { SCREEN_WIDTH / 2 , SCREEN_HEIGHT / 2 , 45, 45};
	// SDL_Rect planetrect3 = { SCREEN_WIDTH / 2 + 400, SCREEN_HEIGHT / 2 - 300, 55, 55};

	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			bool quit = false;

			SDL_Event e;

			ROCKET rocket;

			while( !quit )
			{
				while( SDL_PollEvent( &e ) != 0 )
				{
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}

					rocket.handleEvent( e );
				}

				rocket.move();

				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );

				SDL_RenderCopy( gRenderer, BG, NULL, NULL );
				
				planet[0].render();
				planet[1].render();

				rocket.render();

				SDL_RenderPresent( gRenderer );
			}
		}
	}

	close();

	return 0;
}