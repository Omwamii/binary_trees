#include "binary_trees.h"

/**
 * binary_tree_uncle - find the uncle of a node
 * @node: ptr to node to find the uncle
 *
 * Return: ptr to uncle or null
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || (!node->parent->parent))
		return (NULL);
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	return (node->parent->parent->left);
}
