#include "binary_trees.h"

bst_t *find_parent(bst_t *node, int value);
/**
 * bst_insert - insert into binary search tree
 * @tree: ptr to ptr to root node
 * @value: value to store in node to be inserted
 *
 * Return: ptr to created node, NULL on fail
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *pops, *root, *new_node;

	if (!tree)
		return (NULL);
	root = *tree;
	pops = find_parent(root, value);
	new_node = (bst_t *)binary_tree_node(pops, value);
	if (pops)
	{
		if (!pops->left && pops->n > value)
			pops->left = new_node;
		else
			pops->right = new_node;
	}
	else
	{
		if (!root)
			*tree = new_node;
		else
			return (NULL); /* duplicate value found */
	}
	return (new_node);
}

/**
 * find_parent - recursively find appropriate parent
 * @node: root node of subtree
 * @value: value of node to insert
 *
 * Return: parent node
 */
bst_t *find_parent(bst_t *node, int value)
{
	if (!node || node->n == value)
		return (NULL);
	if ((!node->left && node->n > value) ||
			(!node->right && node->n < value))
		return (node);
	if (value > node->n)
		return (find_parent(node->right, value));
	if (value < node->n)
		return (find_parent(node->left, value));
	return (node);
}
