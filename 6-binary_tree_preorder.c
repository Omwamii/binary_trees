#include "binary_trees.h"

void preorder(binary_tree_t *node, void (*func)(int));
/**
 * binary_tree_preorder - traverses tree in pre-order
 * @tree: pointer to the root node
 * @func: pointer to a function to call for each node
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	preorder((binary_tree_t *)tree, func);
}

/**
 * preorder - recursively visits nodes in a tree
 * @node: ptr to nodeto visit
 * @func: function pointer to call for each node
 */
void preorder(binary_tree_t *node, void (*func)(int))
{
	if (!node)
		return;
	(*func)(node->n);
	preorder(node->left, func);
	preorder(node->right, func);
}
