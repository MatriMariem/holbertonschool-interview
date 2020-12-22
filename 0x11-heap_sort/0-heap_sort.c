#include "sort.h"

/**
 *
 *
 *
 *
 */
 void heap_sort(int *array, size_t size)
 {
   int i;

   for (i = (int)size - 1; i > 0; i--)
   {
     heapify(array, (int)size, i);
   }
 }

/**
 *
 *
 *
 */
void heapify(int *array, int size, int i)
{
  int parent, temp;

  parent = (i - 1) / 2;
  if (!array || (parent < 0 || i >= size) )
  return;
  // printf("parent is %d and i is %d", array[parent], array[i]);
  if (array[parent] < array[i])
  {
    temp = array[parent];
    array[parent] = array[i];
    array[i] = temp;
    print_array((const int *)array, (size_t)size);
    heapify(array, size, (2 * i) + 1);
    heapify(array, size, (2 * i) + 2);
  }
}
