#include "binary_trees.h"

int isfull(binary_tree_t *node);
/**
 * binary_tree_is_full - check if binary tree is full
 * @tree: pointer to the root node
 *
 * Return: 0 if tree is NULL else 1
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (isfull((binary_tree_t *)tree));
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
