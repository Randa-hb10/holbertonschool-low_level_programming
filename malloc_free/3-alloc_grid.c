#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2D array of integers
 * @width: number of columns
 * @height: number of rows
 *
 * Return: pointer to the 2D array, or NULL on failure
 */
int **alloc_grid(int width, int height)
{
int **grid;
int w, h;
if (width <= 0 || height <= 0)
return (NULL);
grid = malloc(sizeof(int *) * height);
if (grid == NULL)
return (NULL);
for (w = 0; w < height; w++)
{
grid[w] = malloc(sizeof(int) * width);
if (grid[w] == NULL)
{
while (w > 0)
{
free(grid[w - 1]);
w--;
}
free(grid);
return (NULL);
}
for (h = 0; h < width; h++)
grid[w][h] = 0;
}
return (grid);
}
