#include "binary_trees.h"

bst_t *find_node(bst_t *node, int value);
/**
 * bst_search - searches for a value in a BST
 * @tree: ptr to the root node of BST
 * @value: value to search in tree
 *
 * Return: ptr to the node with the value else null if
 * not found or tree is null
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	return (find_node((bst_t *)tree, value));
}

/**
 * find_node - recursively find a matching node for the value
 * @node: root node of tree / sub_tree
 * @value: value to search for
 *
 * Return: ptr to the matching node found or null
 */
bst_t *find_node(bst_t *node, int value)
{
	if (!node)
		return (NULL);
	if (node->n == value)
		return (node);
	if (node->n > value)
		return (find_node(node->left, value));
	if (node->n < value)
		return (find_node(node->right, value));
	return (node);
}
