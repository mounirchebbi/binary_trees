#include "binary_trees.h"

/**
 * binary_tree_is_root - Check if node is a  tree root
 * @node: Pointer to the node
 * Return: 1 when true 0 when false
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}
