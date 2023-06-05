#include "binary_trees.h"

size_t size(binary_tree_t *node);
/**
 * binary_tree_size - find height of a tree
 * @tree: ptr to root node
 *
 * Return: height of tree or 0 if tree is null
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (size((binary_tree_t *)tree));
}

/**
 * size - recursively find height of tree
 * @node: ptr to current node (from root)
 *
 * Return: height
 */
size_t size(binary_tree_t *node)
{
	size_t left_size, right_size;

	if (!node)
		return (0);

	left_size = size(node->left);
	right_size = size(node->right);

	return ((left_size  + right_size) + 1);
}
