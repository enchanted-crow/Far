ROCKET::ROCKET()
{
    RAxisX = 0;
    RAxisY = 0;
    RVelocityX = 0;
    RVelocityY = 0;
}

void ROCKET::handleEvent(SDL_Event& e)
{
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: RVelocityY -= ROCKET_VELOCITY_INCREMENT; break;
            case SDLK_DOWN: RVelocityY += ROCKET_VELOCITY_INCREMENT; break;
            case SDLK_LEFT: RVelocityX -= ROCKET_VELOCITY_INCREMENT; break;
            case SDLK_RIGHT: RVelocityX += ROCKET_VELOCITY_INCREMENT; break;
        }
    }
}

void ROCKET::move()
{
    //Move the ROCKET left or right
    double X_displacement = -(RAxisX - SCREEN_WIDTH/2);
    double Y_displacement = -(RAxisY - SCREEN_HEIGHT/2);

    double X1_displacement = -(RAxisX - SCREEN_WIDTH/2 - 400);
    double Y1_displacement = -(RAxisY - SCREEN_HEIGHT/2 + 300);

	double distance = sqrt ( X_displacement*X_displacement  + Y_displacement*Y_displacement );
	double distance1 = sqrt ( X1_displacement*X1_displacement  + Y1_displacement*Y1_displacement );

	if ( distance < 350 )
	{

			if ( X_displacement > 0.001){
				if( !( RVelocityX > 9 )  )
				{
				    //Move back
				    RVelocityX += 1;
				}
			}
			else{
				if( !( RVelocityX < -9 )  )
				{
				    //Move back
				    RVelocityX -= 1;
				}
			}
			if ( Y_displacement > 0.001){;
				if( !( RVelocityY > 9 )  )
				{
				    //Move back
				    RVelocityY += 1;
				}
			}
			else{
				if( ( RVelocityY > 9 )  )
				{
				    //Move back
				    RVelocityY -= 1;
				}
			}
				

	}
	if ( distance1 < 250 )
	{

			if ( X1_displacement > 0.001){
				RVelocityX += 1;
				if( ( RVelocityX > 15 )  )
				{
				    //Move back
				    RVelocityX -= 1;
				}
			}
			else{
				RVelocityX -= 1;
				if( ( RVelocityX < -15 )  )
				{
				    //Move back
				    RVelocityX += 1;
				}
			}
			if ( Y1_displacement > 0.001){
				RVelocityY += 1;
				if( ( RVelocityY > 15 )  )
				{
				    //Move back
				    RVelocityY -= 1;
				}
			}
			else{

				RVelocityY -= 1;
				if( ( RVelocityY <- 15 )  )
				{
				    //Move back
				    RVelocityY += 1;
				}
			}
				

	}

   
    if( ( RVelocityX > 15 )  )
    {
        //Move back
        RVelocityX -= 3;
    }
     if( ( RVelocityX < -15 )  )
    {
        //Move back
        RVelocityX += 3;
    }
    RAxisX += RVelocityX;
    //If the ROCKET went too far to the left or right
    if( ( RAxisX < 0 ) || ( RAxisX + ROCKET_WIDTH > SCREEN_WIDTH ) )
    {
        //Move back
        RAxisX -= RVelocityX;
    }

    //Move the ROCKET up or down
    if( ( RVelocityY > 15 )  )
    {
        //Move back
        RVelocityY -= 3;
    }
     if( ( RVelocityY < -15 )  )
    {
        //Move back
        RVelocityY += 3;
    }
    RAxisY += RVelocityY;

    //If the ROCKET went too far up or down
    if( ( RAxisY < 0 ) || ( RAxisY + ROCKET_HEIGHT > SCREEN_HEIGHT ) )
    {
        //Move back
        RAxisY -= RVelocityY;
    }
}

void ROCKET::render()
{
    double dely = RVelocityY;
    double delx = RVelocityX;

    double angle = atan(dely/delx) * 180 / 3.1415;
    
    if ( dely <= 0 && delx < 0)
    	angle = angle + 180 ;
    if ( delx < 0 && dely > 0)
    	angle = angle + 180;

	gROCKETTexture.render( RAxisX, RAxisY, NULL, angle , NULL, SDL_FLIP_NONE  );
}