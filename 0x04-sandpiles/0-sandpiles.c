#include "sandpiles.h"

/**
 *
 *
 *
 */
void print_grid(int grid[3][3])
{
    int i, j;

	printf("=\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * sandpiles_sum - a function that computes the sum of two sandpiles
 * grid1: first grid
 * grid2: second grid
 * Return: none
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, stable = 1;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			if (grid1[i][j] > 3)
				stable = 0;
		}
	}
	if (stable == 1)
		return;
	else
	{
		stable = 1;
		print_grid(grid1);
	}

}
