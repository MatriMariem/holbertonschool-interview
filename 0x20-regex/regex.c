#include "regex.h"
/**
*/
int regex_match(char const *str, char const *pattern)
{
  if (!str || !pattern)
  return(0);
  if (!str[0] && !pattern[0])
  return(1);
  if (str[0] == pattern[0] || (pattern[0] == '.' && pattern[1] != '*'))
  return (regex_match(str + 1, pattern + 1));
  if (str[0] != pattern[0] && (pattern[0] != '.' && pattern[1] == '*'))
  return (regex_match(str, pattern + 2));
  if (pattern[0] == '.' && pattern[1] == '*')
  {
    if (!pattern[2])
    return (1);
    return(regex_match(str, pattern + 2) || regex_match(str + 1, pattern));
  }
  if (pattern[0] == '*')
  {
    return(regex_match(str + 1, pattern) || regex_match(str, pattern + 1));
  }
  return (0);
}
