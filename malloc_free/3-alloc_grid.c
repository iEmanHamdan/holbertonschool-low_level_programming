#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers
 * @width: width of the grid
 * @height: height of the grid
 *
 * Return: pointer to 2D array, or NULL on failure
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j;

	if (width <= 0 || height <= 0)
		return (NULL);

	/* Step 1: Allocate the row pointers */
	grid = malloc(sizeof(int *) * height);

	if (grid == NULL)
		return (NULL);

	/* Step 2: Allocate each row */
	for (i = 0; i < height; i++)
	{
		grid[i] = malloc(sizeof(int) * width);

		/* Step 3: Handle partial failure */
		if (grid[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(grid[j]);
			free(grid);
			return (NULL);
		}

		/* Initialize to 0 */
		for (j = 0; j < width; j++)
			grid[i][j] = 0;
	}

	return (grid);
}
