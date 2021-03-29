#include "holberton.h"
/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int wildcmp(char *s1, char *s2)
{
  if (!s1 || !s2)
  return (0);
  if (!s1[0] && !s2[0])
  return (1);
  if (s2[0] == '*')
  {
    if (!s1[0] && s2[1])
    return (0);
    else if (wildcmp(s1, s2 + 1))
    return (1);
  else
  return(wildcmp(s1 + 1, s2));
  }
  if (s1[0] == s2[0])
  return (wildcmp(s1 + 1, s2 + 1));
  else
  return (0);
}
