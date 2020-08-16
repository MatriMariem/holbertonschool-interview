#include "sandpiles.h"

/**
 * sandpiles_sum - a function that computes the sum of two sandpiles
 * grid1: first grid
 * grid2: second grid
 * Return: none
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			grid1[i][j] += grid2[i][j];
			printf("%d", grid1[i][j]);
		}
		printf("\n");
	}

}
