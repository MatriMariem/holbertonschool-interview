#ifndef SUB
#define SUB

#include <stdlib.h>
#include <stdio.h>

int *find_substring(char const *s, char const **words, int nb_words, int *n);
void reset_tracker(int *tracker, int nb_words);
int contains_zeroes(int *tracker, int nb_words);
int all_zeroes(int *tracker, int nb_words);
int compare(char *s, char *word);
int *fill_indices(int *raw_idx, int *indices, int *n);


#endif
