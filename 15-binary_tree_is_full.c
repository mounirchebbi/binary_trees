#include "binary_trees.h"

/**
 * recursive_check - recursive check
 * @tree: pointer to tree
 * Return: 1 when true 0 when false
 */
int recursive_check(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
		    (tree->left == NULL && tree->right != NULL) ||
		    recursive_check(tree->left) == 0 ||
		    recursive_check(tree->right) == 0)
			return (0);
	}
	return (1);
}

/**
 * binary_tree_is_full - Checks if tree is full
  * @tree: pointer to tree
  * Return: 1 when true 0 when false
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (recursive_check(tree));
}
