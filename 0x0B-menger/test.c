#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *border_line(char *proto, int size)
{
	int len, i, c, times;
	char *border, *center, *p_copy, *line;

	len = ((size + 1) * (size / 3)) + 1;
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
    line = strtok(NULL, "\n");
	}
  center[c] = '\0';
	border[c] = '\0';
	free(p_copy);
  printf("center is %s", center);
  free(center);
	return (border);
}
int main()
{
  char *border, *proto;
  proto = malloc(sizeof(char) * 3);
  proto[0] = '#';
  proto[1] = '\n';
  proto[2] = '\0';
  printf("proto is\n");
  printf("%s", proto);
  border = border_line(proto, 3);
  printf("border is\n");
  printf("%s", border);
  free(border);
  return (0);
}
