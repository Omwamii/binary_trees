#include "binary_trees.h"

size_t count_leaves(binary_tree_t *node);
/**
 * binary_tree_leaves - find height of a tree
 * @tree: ptr to root node
 *
 * Return: height of tree or 0 if tree is null
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (count_leaves((binary_tree_t *)tree));
}

/**
 * count_leaves - recursively find leaves of sub-trees
 * @node: ptr to current node (from root)
 *
 * Return: height
 */
size_t count_leaves(binary_tree_t *node)
{
	size_t num_leaves = 0;

	if (!node)
		return (0);
	if (node->left == node->right) /* null */
		return (++num_leaves);

	num_leaves += (count_leaves(node->left));
	num_leaves += (count_leaves(node->right));
	return (num_leaves);
}
