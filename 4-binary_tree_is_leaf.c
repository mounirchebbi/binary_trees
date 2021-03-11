#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Check if a node is leaf
 * @node: A pointer to the node
 *
 * Return: 1 when true 0 when false
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);
	return (1);
}
