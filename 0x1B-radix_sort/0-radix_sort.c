#include "sort.h"

/**
 *
 *
 */
void radix_sort(int *array, size_t size)
{
	int i, max, digits;

	max = array[0];
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	digits = 1;
	while (max > 0)
	{
		max /= 10;
    sorting_by_digits(array, size, digits);
    digits *= 10;
    print_array((const int *)array, size);
	}
}

void sorting_by_digits(int *array, size_t size, int power)
{
	integer_t *buckets[10], *tmp;
	int i, d, j;

	for (i = 0; i < 10; i++)
		buckets[i] = NULL;
	for (i = 0; i < (int)size; i++)
	{
		d = (array[i] / power) % 10;
		add_node(&buckets[d], array[i]);
	}
	j = 0;
	for (i = 0; i < 10; i++)
	{
		tmp = buckets[i];

		while(tmp)
		{
			array[j] = tmp->n;
			tmp = tmp->next;
			j++;
		}
		free_list(buckets[i]);
	}
}

integer_t *add_node(integer_t **bucket, int n)
{
	integer_t *tmp, *node;

	node = malloc(sizeof(integer_t));
	if (!node)
		return (NULL);
	node->n = n;
	node->next = NULL;
	if (!bucket || !(*bucket))
	{
		*bucket = node;
	}
	else {
		tmp = *bucket;
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = node;

	}
	return (node);

}


/**
 * free_list - frees a integer_t list
 * @head: pointer to list to be freed
 * Return: void
 */
void free_list(integer_t *head)
{
	integer_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}
