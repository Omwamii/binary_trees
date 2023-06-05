#include "binary_trees.h"

void postorder(binary_tree_t *node, void (*func)(int));
/**
 * binary_tree_postorder - traverses tree in pre-order
 * @tree: pointer to the root node
 * @func: pointer to a function to call for each node
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	postorder((binary_tree_t *)tree, func);
}

/**
 * postorder - recursively visits nodes in a tree
 * @node: ptr to nodeto visit
 * @func: function pointer to call for each node
 */
void postorder(binary_tree_t *node, void (*func)(int))
{
	if (!node)
		return;
	postorder(node->left, func);
	postorder(node->right, func);
	(*func)(node->n);
}
