#include "binary_trees.h"

int isfull(binary_tree_t *node);
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
		return (isfull((binary_tree_t *)tree));
	return (0);
}

/**
 * isfull - find if subtree is full
 * @node: pointer to root node
 *
 * Return: 0 if not full, 1 if full
 */
int isfull(binary_tree_t *node)
{
	int full;

	if (!node)
		return (1);
	if ((node->left == node->right) || (node->left && node->right))
		full = 1;
	else
		full = 0;
	full *= isfull(node->left);
	full *= isfull(node->right);

	return (full);

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
