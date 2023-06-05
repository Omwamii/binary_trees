#include "binary_trees.h"

size_t size(binary_tree_t *node);
size_t height(binary_tree_t *node);
/**
 * binary_tree_is_perfect - check if binary tree is full
 * @tree: pointer to the root node
 *
 * Return: 0 if tree is NULL else 1
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	/* if left subtree height is same as right */
	if (height(tree->left) == height(tree->right))
	{
		/* if both sub-trees have same size */
		if (size(tree->left) == size(tree->right))
			return (1);
	}
	return (0);
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
