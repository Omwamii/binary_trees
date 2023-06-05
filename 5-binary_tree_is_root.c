#include "binary_trees.h"

/**
 * binary_tree_is_root - check if a node is a root node
 * @node: pointer to node to check
 *
 * Return: 1 if yes, 0 otherwise
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (!(node->parent))
		return (1);
	else
		return (0);
}
