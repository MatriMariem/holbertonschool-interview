#include "menger.h"

/**
 *
 *
 *
 *
 */
void menger(int level)
{
	char *prototype;
	int l;

	if (level < 0)
		return;
	if (level = 0)
	{
		printf("#\n");
		return;
	}
	prototype = malloc(sizeof(char) * 3);
	prototype[0] = '#';
	prototype[1] = '\n';
	prototype[2] = '\0';
	l = 0;
	while (l < level)
	{
		l++;
		prototype = level_up(prototype, l);
	}
	printf("%s", prototype);
	free(prototype);
	return;
}

/**
 *
 *
 *
 *
 */
char *level_up(char *proto, int level)
{
	char *border, *center;
	double size;
	size = pow((double)3, (double)level);
	return (build_sponge(proto, (int)size));
}
/*
 *
 *
 */
char *build_sponge(char *proto, int size)
{
	int len, i, c, times;
	char *border, *center, *p_copy, *line;

	len = (size + 1) * (size / 3) + 1;
	border = malloc(sizeof(char) * len);
	center = malloc(sizeof(char) * len);
	p_copy = strdup((const char *)proto);
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
		line = strtok(NULL, '\n');
	}
	center[c] = '\0';
	border[c] = '\0';
	free(p_copy);
	free(proto);
	proto = concatenate_all(border, center, border);
	free(border);
	free(center);
	return (proto);
}

char *concatenate_all(char *border, char *center, char *border)
{
	char *sponge;

	sponge = malloc(sizeof(char) * );
}
