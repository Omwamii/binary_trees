#include "binary_trees.h"

size_t count_nodes(binary_tree_t *node);
/**
 * binary_tree_nodes - counts the nodes with at least 1 child
 * @tree: pointer to the root nodes
 *
 * Return: 0 if tree is Null or number of nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (count_nodes((binary_tree_t *)tree));
}

/**
 * count_nodes - recursively find leaves of sub-trees
 * @node: ptr to current node (from root)
 *
 * Return: height
 */
size_t count_nodes(binary_tree_t *node)
{
	size_t num_nodes = 0;

	if (!node)
		return (0);
	if (node->left != node->right) /* null */
		++num_nodes;
	num_nodes += (count_nodes(node->left));
	num_nodes += (count_nodes(node->right));
	return (num_nodes);
}
