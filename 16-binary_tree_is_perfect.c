#include "binary_trees.h"

unsigned char is_leaf(const binary_tree_t *node);
size_t depth(const binary_tree_t *tree);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * is_leaf - checks if node is a leaf
 * @node: pointer to node
 * Return: 1 when true, 0 when false
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth - depth of node
 * @tree: pointer to tree
 * Return: depth of node
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - get a leaf
 * @tree: pointer to tree
 * Return: pointer to the first leaf
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * check_recursive - recursive check
 * @tree: pointer to tree
 * @leaf_depth: depth of leaf
 * @level: Level of current node
 * Return: 1 when true 0 when false
 */
int check_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (check_recursive(tree->left, leaf_depth, level + 1) &&
		check_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Check if a binary tree is perfect
 * @tree: pointer to tree
 * Return: 1 when true 0 when false
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}
