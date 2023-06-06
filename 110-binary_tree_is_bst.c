#include "binary_trees.h"

int is_bst(binary_tree_t *node);
int max_val(binary_tree_t *node);
int min_val(binary_tree_t *node);
/**
 * binary_tree_is_bst - check if a tree is a valid BST
 * @tree: pointer to the root node of tree
 *
 * Return: 0 if tree is NULL, else 1 if tree is BST
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (is_bst((binary_tree_t *)tree));
}

/**
 * is_bst - recursively check if tree is a bst
 * @node: root node
 *
 * Return: 1 if bst, 0 otherwise
 */
int is_bst(binary_tree_t *node)
{
	if (!node)
		return (1);

	if (node->left && max_val(node->left)
			> node->n)
		return (0);

	if (node->right && min_val(node->right)
			< node->n)
		return (0);

	if (!is_bst(node->left) || !is_bst(node->right))
		return (0);
	return (1);
}

/**
 * max_val - find max val in subtree
 * @node: root node
 *
 * Return: max value
 */
int max_val(binary_tree_t *node)
{
	int left_max, right_max, val = 0;

	if (!node)
		return (0);
	left_max = max_val(node->left);
	right_max = max_val(node->right);

	if (left_max > right_max)
		val = left_max;
	else
		val = right_max;
	if (val < node->n)
		val = node->n;
	return (val);
}

/**
 * min_val - find max val in subtree
 * @node: root node
 *
 * Return: max value
 */
int min_val(binary_tree_t *node)
{
	int left_min, right_min, val = 0;

	if (!node)
		return (1000000000);
	left_min = min_val(node->left);
	right_min = min_val(node->right);

	if (left_min < right_min)
		val = left_min;
	else
		val = right_min;
	if (val > node->n)
		val = node->n;
	return (val);
}
