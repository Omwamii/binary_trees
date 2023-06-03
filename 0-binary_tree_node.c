#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to parent node
 * @value: value of the node
 *
 * Return: pointer to node created
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (!node)
		return (NULL);
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	node->n = value;
	return (node);
}
