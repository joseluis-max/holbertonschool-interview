#include "sandpiles.h"

/**
 * copy - copy sandpile in other sandpile
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 * Return: void
 */
void copy(int grid2[3][3], int grid1[3][3])
{
	int row, column;

	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < 3; column++)
			grid1[row][column] = grid2[row][column];
	}
}

/**
 * zeros - fill great with zeros sand
 * @grid: 3x3 grid
 * Return: void
 */
void zeros(int grid[3][3])
{
	int row, column;

	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < 3; column++)
			grid[row][column] = 0;
	}
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int row, column;

	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < 3; column++)
		{
			if (column)
				printf(" ");
			printf("%d", grid[row][column]);
		}
		printf("\n");
	}
}

/**
 * is_unstable - check if sandpile is stable or not
 * @grid: sandpile
 * Return: 1 if is unstable and 0 if is stable.
 */
int is_unstable(int grid[3][3])
{
	int row, column;

	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < 3; column++)
		{
			if (grid[row][column] > 3)
				return (1);
		}
	}
	return (0);
}

/**
 * sandpiles_sum - sum two sandpiles
 * @grid1: stable sandpile.
 * @grid2: stable sandpile.
 * Return: When sum is done grid1 stable is returned.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int row, column;

	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < 3; column++)
		{
			grid1[row][column] = grid1[row][column] + grid2[row][column];
		}
	}
	while (is_unstable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		zeros(grid2);
		for (row = 0; row < 3; row++)
		{
			for (column = 0; column < 3; column++)
			{
				if (grid1[row][column] > 3)
				{
					grid2[row][column] +=  grid1[row][column] - 4;
					if (row - 1 >= 0)
						grid2[row - 1][column] += 1;
					if (column + 1 <= 2)
						grid2[row][column + 1] += 1;
					if (row + 1 <= 2)
						grid2[row + 1][column] += 1;
					if (column - 1 >= 0)
						grid2[row][column - 1] += 1;
				}
				else
					grid2[row][column] += grid1[row][column];
			}
		}
		copy(grid2, grid1);
	}
}
