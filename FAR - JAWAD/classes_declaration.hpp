class LTexture
{
	public:
		//Initializes variables
		LTexture();

		//Deallocates memory
		~LTexture();

		//Loads image at specified path
		bool loadFromFile( std::string path );
		
		#if defined(_SDL_TTF_H) || defined(SDL_TTF_H)
		//Creates image from font string
		bool loadFromRenderedText( std::string textureText, SDL_Color textColor );
		#endif

		//Deallocates texture
		void free();
		
		//Renders texture at given point
		void render( int x, int y, SDL_Rect* clip, double angle , SDL_Point* center, SDL_RendererFlip flip  );

		//Gets image dimensions
		int getWidth();
		int getHeight();

	private:
		//The actual hardware texture
		SDL_Texture* Texture;

		//Image dimensions
		int LWidth;
		int LHeight;
};

class ROCKET
{
	public:

		static const int ROCKET_WIDTH = 40;
		static const int ROCKET_HEIGHT = 25;
		static const int ROCKET_VELOCITY_INCREMENT = 03;

		ROCKET();

		void handleEvent( SDL_Event& e );

		void move();

		void render();

		int RAxisX;
		int RAxisY;
		int RVelocityX;
		int RVelocityY;
		int RCenterX;
		int RCenterY;

		// NOT BEING USED YET.. chaile use kora jabe
		SDL_Rect *RDestinationRect;
		SDL_Texture *RTexture;
};

class PLANET
{
	public:

		void PInit(int X, int Y, int R, int M);

		void LoadPlanetTexture(std::string path);

		void render();

		void free();

		int PRadius;
		int PMass;
		int PCenterX;
		int PCenterY;
		int PAxisX;
		int PAxisY;

		SDL_Rect PDestinationRect;
		SDL_Texture *PTexture;
};
