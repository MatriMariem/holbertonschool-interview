#include "menger.h"

/**
 *
 *
 *
 *
 */
void menger(int level)
{
	char *sponge;
	int l;

	if (level < 0)
		return;
	if (level == 0)
	{
		printf("#\n");
		return;
	}
	sponge = malloc(sizeof(char) * 3);
	sponge[0] = '#';
	sponge[1] = '\n';
	sponge[2] = '\0';
	l = 0;
	while (l < level)
	{
		l++;
		sponge = level_up(sponge, l);
	}
	printf("%s", sponge);
	free(sponge);
	return;
}

/**
 *
 *
 *
 *
 */
char *level_up(char *sponge, int level)
{
	double size;

	size = pow((double)3, (double)level);
	return (build_sponge(sponge, (int)size));
}
/*
 *
 *
 */
char *build_sponge(char *sponge, int size)
{
	int len, i, c, times;
	char *border, *center, *p_copy, *line;

	len = (size + 1) * (size / 3) + 1;
	border = malloc(sizeof(char) * len);
	center = malloc(sizeof(char) * len);
	p_copy = strdup((const char *)sponge);
	line = strtok(p_copy, "\n");
	i = 0;
	c = 0;
	for (times = 0; times < 3; times++)
	{
		i = 0;
		while (line[i])
		{
			if (times != 1)
			{
			center[c] = line[i];
			}
			else
			{
				center[c] = ' ';
			}
			border[c] = line[i];
			i++;
			c++;
		}
	}
	center[c] = '\n';
	border[c] = '\n';
	c++;
	line = strtok(NULL, "\n");
	while (line)
	{
		for (times = 0; times < 3; times++)
		{
			i = 0;
			while (line[i])
			{
				if (times != 1)
				{
				center[c] = line[i];
				}
				else
				{
					center[c] = ' ';
				}
				border[c] = line[i];
				i++;
				c++;
			}
		}
		center[c] = '\n';
		border[c] = '\n';
		c++;
		line = strtok(NULL, "\n");
	}
	center[c] = '\0';
	border[c] = '\0';
	free(p_copy);
	free(sponge);
	sponge = concatenate(border, center, size);
	free(border);
	free(center);
	return (sponge);
}

char *concatenate(char *border, char *center, int size)
{
	char *sponge;
	int len, i, c;

	len = ((size + 1) * size) + 1;
	sponge = malloc(sizeof(char) * len);
	c = 0;
	for (i = 0; border[i]; i++)
	{
		sponge[c] = border[i];
		c++;
	}
	for (i = 0; center[i]; i++)
	{
		sponge[c] = center[i];
		c++;
	}
	for (i = 0; border[i]; i++)
	{
		sponge[c] = border[i];
		c++;
	}
	sponge[c] = '\0';
	return (sponge);
}
