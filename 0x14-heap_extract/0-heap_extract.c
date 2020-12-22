#include "binary_trees.h"

/**
 *
 *
 *
 *
 */
int heap_extract(heap_t **root)
 {
   heap_t **array;
   if (!root || !*root)
   return(0);
   n = (*root)->n;
   // size = get_size(*root);
   // array = malloc(size * sizeof(heap_t *));
   // if (!array)
   // return(0);
   // for (i = 0; i < size; i++)
   // array[i] = NULL;
   // heap_to_array(array, *root, 0);
   node = (*root);
   if (!node->left)
   {
   if (node->parent)
   {
     if (node->parent->left == node)
     node->parent->left = NULL;
     else
     node->parent->right = NULL;
   }
   free(node);
 }
   else if (!node->right || node->left->n >= node->right->n)
   return;
   else if (node->left->n < node->right->n)
   return;


   return(n);
 }

/**
 *
 *
 */
int get_size(heap_t *root)
{
  return (root ? 1 + get_size(root->left) + get_size(root->right) : 0);
}

heap_to_array(array, root, index)
{
  array[index] = root;
  if (root)
  {
    heap_to_array(array, root->left, (index * 2) + 1);
  heap_to_array(array, root->right, (index * 2) + 2);
}
}
