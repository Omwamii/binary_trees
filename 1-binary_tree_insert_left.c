#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left child of another node
 * @parent: pointer to parent node
 * @value: value of node
 *
 * Return: pointer to created node or Null if fail or parent is Null
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL, *old;

	if (!parent)
		return (NULL);
	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->right = NULL;
	node->left = NULL;

	old = parent->left;
	if (!old) /* parent has no left child */
		parent->left = node;
	else
	{
		node->left = old;
		old->parent = node;
		parent->left = node;
	}
	return (node);
}
