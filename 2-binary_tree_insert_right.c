#include "binary_trees.h"

/**
 * binary_tree_insert_right - insert node to the right
 * @parent: pointer to parent node
 * @value: value of node
 *
 * Return: pointer to created node or Null if fail or parent is null
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node, *old;

	if (!parent)
		return (NULL);
	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);
	node->n = value;
	node->left = NULL;
	node->right = NULL;
	node->parent = parent;

	old = parent->right;
	if (!old) /* no right child */
		parent->right = node;
	else
	{
		node->right = old;
		old->parent = node;
		parent->right = node;
	}
	return (node);
}
