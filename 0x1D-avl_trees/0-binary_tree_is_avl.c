#include "binary_trees.h"
int height(binary_tree_t *tree)
{
  int hl, hr;

  if (!tree)
  return (-1);
  hl = height(tree->left);
  hr = height(tree->right);
  return (hl > hr ? hl + 1 : hr + 1);
}
int binary_tree_is_avl(const binary_tree_t *tree)
{
  if (!tree)
  return (0);
  if (tree->left && (tree->left)->n > tree->n)
  return (0);
  if (tree->right && (tree->right)->n < tree->n)
  return (0);
  if (height(tree->left) - height(tree->right) > 1 || height(tree->left) - height(tree->right) < -1)
  return (0);
  if (!tree->left && !tree->right)
  return (1);
  if (!tree->left)
  return (1 * binary_tree_is_avl(tree->right));
  if (!tree->right)
  return (1 * binary_tree_is_avl(tree->left));
  return (1 * binary_tree_is_avl(tree->left) * binary_tree_is_avl(tree->right));
}
