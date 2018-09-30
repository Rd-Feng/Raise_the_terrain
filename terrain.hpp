//
//  terrain.hpp
//  Raise_the_terrain
//
//  Created by Raymond Feng on 9/21/18.
//  Copyright © 2018 Raymond Feng. All rights reserved.
//

#ifndef terrain_hpp
#define terrain_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init(SDL_Window **gWindow, SDL_Renderer **rend);

//Frees media and shuts down SDL
void close(SDL_Window **gWindow, SDL_Renderer **rend);

void draw_line(SDL_Renderer *rend, double x1, double y1, double z1, double x2, double y2, double z2);

void project(double x, double y, double z, double incl, double *wx, double *wy);

void init_grid(double grid[8][8][3], double square_size, double z[8][8]);

#endif /* terrain_hpp */
