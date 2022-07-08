#include "menger.h"


/**
 * menger - draw 2D Menger Sponge
 * @level: Menger sponge level
 */
void menger(int level)
{
	int i, j, size, row, col;
	char sim;

	size = pow(3, level);

	for (i = 0; i < level; i++)
	{
		for (j = 0; j < level; j++)
		{
			row = i;
			col = j;
			sim = '#';
			while (row > 0)
			{
				if (row % 3 == 1 && col % 3 == 1)
				{
					sim = ' ';
				}
				row /= 3;
				col /= 3;
			}
			printf("%c", sim);
		}
		printf("\n");
	}
}
