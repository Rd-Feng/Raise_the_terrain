#include "terrain.hpp"

void project(double x, double y, double z, double incl, double *wx, double *wy)
{
    *wx = incl * x - incl * y;
    *wy = (1 - incl) * x + (1 - incl) * y - z;
}

void init_grid(double grid[8][8][3], double square_size, double z[8][8])
{
    int i, j;
    double coord, d;
    
    d = square_size * 7 / 2;
    /* x */
    for (i = 0; i < 8; i++)
        for (j = 0, coord = 0; j < 8; j++, coord += square_size)
            grid[i][j][0] = coord - d;
    /* y */
    for (i = 0, coord = 0; i < 8; i++, coord += square_size)
        for (j = 0; j < 8; j++)
            grid[i][j][1] = coord - d;
    /* z */
    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++)
            grid[i][j][2] = z[i][j] / 1.8;
    
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
            printf("%.0f ", grid[i][j][2]);
        printf("\n");
    }
}
