#include "slide_line.h"
/**
 * swap - swaped numbers position
 * @line: array represent a line game
 * @i: init position
 * @j: end position
 */
void swap(int *line, size_t i, size_t j)
{
	int tmp = 0;

	tmp = line[i];
	line[i] = line[j];
	line[j] = tmp;
}

/**
 * order - put zeros to the end of the line
 * @line: array represent a line game
 * @direction: direction for make the merge
 * @size: size of line
 */
void order(int *line, size_t size, int direction)
{
	size_t i = 0, j = 0;
	int jj = 0;
	int ii;

	if (direction)
	{
		for (ii = (int)size - 1; ii > 0; ii--)
		{
			if (line[ii] == 0)
			{
				for (jj = ii - 1; jj >= 0; jj--)
				{
					if (line[jj] != 0)
					{
						swap(line, ii, jj);
						break;
					}
				}
			}
		}
	}
	else
	{
		for (i = 0; i < size; i++)
		{
			if (line[i] == 0)
			{
				for (j = i + 1; j < size; j++)
				{
					if (line[j] != 0)
					{
						swap(line, i, j);
						break;
					}
				}
			}
		}
	}
}
/**
 * slide_line - slide and merge array of numbers
 * @line: array represent a line game
 * @direction: direction for make the merge
 * @size: size of line
 * Return: 1 success, or 0 failure
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i;
	int ii;

	/* order numbers in the right */
	order(line, size, direction);
	if (direction)
	{
		for (ii = (int)size; ii > 0; ii -= 2)
		{
			if (line[ii - 1] == line[ii - 2])
			{
				line[ii - 1] *= 2;
				line[ii - 2] = 0;
			}
			else if (line[ii - 2] == line[ii - 3])
			{
				line[ii - 2] *= 2;
				line[ii - 3] = 0;
			}
		}
	}
	else
	{
		for (i = 0; i < size; i += 2)
		{
			if (line[i] == line[i + 1])
			{
				line[i] *= 2;
				line[i + 1] = 0;
			}
			else if (line[i + 1] == line[i + 2])
			{
				line[i + 1] *= 2;
				line[i + 2] = 0;
			}
		}
	}
	order(line, size, direction);
	return (1);
}
