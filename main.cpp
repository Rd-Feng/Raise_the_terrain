#include "terrain.hpp"

SDL_Window *window = NULL; /* 640 x 480 */
SDL_Renderer *renderer = NULL;
//SDL_Surface *gScreenSurface = NULL;
SDL_Event e;
double wx1 = 0, wx2 = 0, wy1 = 0, wy2 = 0;
double incl = 0.7;
double g[8][8][3] = {0};
double z[8][8] = {
    {120, 60, 40, 60, 20, -20, -80, -120},
    {40, 20, 30, 30, -10, -40, -90, -110},
    {20, 30, 10, 06, -6, -20, -26, -90},
    {00, -6, 10, 10, -6, -20, -20, -40},
    {-20, -20, -18, -14, -40, -20, -20, -30},
    {-10, -10, -10, -10, -8, -20, -20, -30},
    {20, 10, 10, 10, 10, 04, 10, -10},
    {30, 24, 24, 22, 20, 18, 14, 16}
};

int main( int argc, char* args[] )
{
    int i, j;
    
    init_grid(g, 60, z);
    if (!init(&window, &renderer))
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        bool quit = false;
        while (!quit)
        {
            while (SDL_PollEvent(&e)){
                if (e.type == SDL_QUIT){
                    quit = true;
                }
                if (e.type == SDL_KEYDOWN)
                {
                    
                    if (e.key.keysym.sym == SDLK_ESCAPE)
                        quit = true;
                }
                /* draw  grid*/
                for (i = 0; i < 8; i++)
                    for (j = 0; j < 7; j++)
                        draw_line(renderer, g[j][i][0], g[j][i][1], g[j][i][2],
                                  g[j + 1][i][0], g[j + 1][i][1], g[j + 1][i][2]);
                for (i = 0; i < 8; i++)
                    for (j = 0; j < 7; j++)
                        draw_line(renderer, g[i][j][0], g[i][j][1], g[i][j][2],
                                  g[i][j + 1][0], g[i][j + 1][1], g[i][j + 1][2]);
                SDL_RenderPresent(renderer);
            }
        }
    }
    close(&window, &renderer);
    return 0;
}

void draw_line(SDL_Renderer *rend, double x1, double y1, double z1, double x2, double y2, double z2)
{
    //z1 = z2 = 0;
    project(x1, y1, z1, incl, &wx1, &wy1);
    project(x2, y2, z2, incl, &wx2, &wy2);
    //wx1 = x1; wx2 = x2; wy1 = y1; wy2 = y2;
    wx1 += SCREEN_WIDTH / 2;
    wx2 += SCREEN_WIDTH / 2;
    wy1 += SCREEN_HEIGHT / 2;
    wy2 += SCREEN_HEIGHT / 2;

    SDL_RenderDrawLine(renderer, wx1, wy1, wx2, wy2);
}
