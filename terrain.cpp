//
//  terrain.cpp
//  Raise_the_terrain
//
//  Created by Raymond Feng on 9/21/18.
//  Copyright © 2018 Raymond Feng. All rights reserved.
//

#include "terrain.hpp"

//Starts up SDL and creates window and get surface
bool init(SDL_Window **window, SDL_Renderer **rend) {
    //Initialization flag
    bool success = true;
    
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        *window = SDL_CreateWindow( "Raise_the_terrain",
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SCREEN_WIDTH, SCREEN_HEIGHT,
                                    SDL_WINDOW_SHOWN );
        if(!*window)
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        else
        {
            *rend = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
            if (!*rend)
                printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
            else
                success = true;
        }
    }
    
    return success;
}


//Frees window and shuts down SDL
void close(SDL_Window **window, SDL_Renderer **rend){
    SDL_DestroyRenderer(*rend);
    SDL_DestroyWindow(*window);
    *window = NULL;
    *rend = NULL;
    //Quit SDL subsystems
    SDL_Quit();
}
