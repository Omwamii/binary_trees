#include "binary_trees.h"

int is_max_heap(binary_tree_t *root);
/**
 * binary_tree_is_heap - check if tree is a max heap
 * @tree: ptr to the root node
 *
 * Return: 1 if max heap 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_max_heap((binary_tree_t *)tree));
}

/**
 * is_max_heap - recursively determine if a tree is a max heap tree
 * @root: ptr to the root node of the tree
 *
 * Description: max heap must be a complete tree and the value of the root
 * node must be maximum among all values in the tree and this should be true
 * recursively
 *
 * Return: 0 if not max heap otherwise 1
 */
int is_max_heap(binary_tree_t *root)
{
	if (!root)
		return (1);
	if (!root->left && root->right) /* not a complete tree */
		return (0);
	if ((root->left && root->left->n > root->n)
			|| (root->right && root->right->n > root->n))
		return (0);
	return (is_max_heap(root->left) && is_max_heap(root->right));
}
