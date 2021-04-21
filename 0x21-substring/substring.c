#include "substring.h"
/**
 *
 *
 *
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int i, j, full_loop, x, l, duble = 0, next_word = -1, idx = 0;
	int *indices = NULL, *tracker;
	int raw_idx[1024];
	for (i = 0; i < 1024; i++)
		raw_idx[i] = -1;
	i = 0;
	tracker = malloc(sizeof(int) * nb_words);
	for (j = 0; j < nb_words; j++)
		tracker[j] = 0;
	while (contains_zeroes(tracker, nb_words) && s[i]) {
		full_loop = 1;
		for (x = 0; x < nb_words; x++)
		{
			duble = 0;
			if (tracker[x] == 0)
			{
				l = compare((char *)&s[i], (char *)words[x]);
			}
			else
			{
				duble = 1;
				l = -1;
			}
			if (l != -1)
			{
				if (all_zeroes(tracker, nb_words))
				{
					raw_idx[idx] = i;
					next_word = i + l;
				}
				full_loop = 0;
				i += l;
				tracker[x] = 1;
				break;
			}
		}
		if (!contains_zeroes(tracker, nb_words))
		{
			idx++;
			for (j = 0; j < nb_words; j++)
				tracker[j] = 0;
		}
		if (full_loop || (!s[i] && contains_zeroes(tracker, nb_words)))
		{
			raw_idx[idx] = -1;
			for (j = 0; j < nb_words; j++)
				tracker[j] = 0;

			if (s[i] && duble && next_word != -1)
			{
				i = next_word;
			}
			else
			{
				i++;
			}
		}
	}
	indices = fill_indices(raw_idx, indices, n);
	free(tracker);
	return(indices);
}
int contains_zeroes(int *tracker, int nb_words)
{
	int i;

	for (i = 0; i < nb_words; i++)
	{
		if (tracker[i] == 0)
			return(1);
	}
	return(0);
}
int all_zeroes(int *tracker, int nb_words)
{
	int i;

	for (i = 0; i < nb_words; i++)
	{
		if (tracker[i] == 1)
			return(0);
	}
	return(1);
}
int compare(char *s, char *word)
{
	int i = 0;

	if (!s[i] && !word[i])
		return (0);
	while (word[i])
	{
		if (s[i] != word[i])
			return(-1);
		i++;
	}
	return(i);
}
int *fill_indices(int *raw_idx, int *indices, int *n)
{
	int i = 0;
	while (raw_idx[i] != -1)
		i++;
	*n = i;
	indices = malloc(sizeof(int) * (*n));
	if (!indices)
	{
		*n = 0;
		return (NULL);
	}
	for (i = 0; i < (*n); i++)
	{
		indices[i] = raw_idx[i];
	}
	return(indices);
}
