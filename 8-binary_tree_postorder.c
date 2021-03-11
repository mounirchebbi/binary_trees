#include "binary_trees.h"

/**
 * binary_tree_postorder - post-order traversal
 * @tree: pointer to tree root
 * @func: function pointer
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
