#include "binary_trees.h"

void inorder(binary_tree_t *node, void (*func)(int));
/**
 * binary_tree_inorder - traverses tree in pre-order
 * @tree: pointer to the root node
 * @func: pointer to a function to call for each node
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	inorder((binary_tree_t *)tree, func);
}

/**
 * inorder - recursively visits nodes in a tree
 * @node: ptr to nodeto visit
 * @func: function pointer to call for each node
 */
void inorder(binary_tree_t *node, void (*func)(int))
{
	if (!node)
		return;
	inorder(node->left, func);
	(*func)(node->n);
	inorder(node->right, func);
}
