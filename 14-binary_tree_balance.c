#include "binary_trees.h"

int height(binary_tree_t *node);
/**
 * binary_tree_balance - measures balance factor of tree
 * @tree: pointer to root node
 *
 * Return: 0 if tree is NUll else ret balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);
	left_height = (height(tree->left) - 1);
	right_height = (height(tree->right) - 1);
	return (left_height - right_height);
}

/**
 * height - recursively find height of tree
 * @node: ptr to current node (from root)
 *
 * Return: height
 */
int height(binary_tree_t *node)
{
	int left_height, right_height;

	if (!node)
		return (0);

	left_height = height(node->left);
	right_height = height(node->right);

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}
