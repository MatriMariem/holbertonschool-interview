#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @argc : number of arguments
 * @argv: array of pointers to arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int i, l1, l2, cp1, cp2, dex;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	for (i = 0; argv[1][i]; i++)
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
		{
			printf("Error\n");
			exit(98);
		}
	}
	l1 = i;
	for (i = 0; argv[2][i]; i++)
	{
		if (argv[2][i] < '0' || argv[2][i] > '9')
		{
			printf("Error\n");
			exit(98);
		}
	}
	l2 = i;
	cp1 = 0;
	dex = 1;
	for (i = l1 - 1; i >= 0; i--)
	{
		cp1 += (argv[1][i] - '0') * dex;
		dex *= 10;
	}
	cp2 = 0;
	dex = 1;
	for (i = l2 - 1; i >= 0; i--)
	{
		cp2 += (argv[2][i] - '0') * dex;
		dex *= 10;
	}
	printf("%d\n", cp1 * cp2);
	return (0);
}
