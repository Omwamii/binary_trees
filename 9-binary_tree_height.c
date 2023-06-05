#include "binary_trees.h"

size_t height(binary_tree_t *node);
/**
 * binary_tree_height - find height of a tree
 * @tree: ptr to root node
 *
 * Return: height of tree or 0 if tree is null
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (height((binary_tree_t *)tree) - 1);
}

/**
 * height - recursively find height of tree
 * @node: ptr to current node (from root)
 *
 * Return: height
 */
size_t height(binary_tree_t *node)
{
	size_t left_height, right_height;

	if (!node)
		return (0);

	left_height = height(node->left);
	right_height = height(node->right);

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}
