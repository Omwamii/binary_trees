#include "binary_trees.h"

size_t tree_size(binary_tree_t *tree);
int is_max_heap(binary_tree_t *root, size_t index, size_t size);
int is_complete(binary_tree_t *root, size_t index, size_t size);
/**
 * binary_tree_is_heap - check if tree is a max heap
 * @tree: ptr to the root node
 *
 * Return: 1 if max heap 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);
	size = tree_size((binary_tree_t *)tree);
	return (is_max_heap((binary_tree_t *)tree, 0, size));
}

/**
 * is_max_heap - recursively determine if a tree is a max heap tree
 * @root: ptr to the root node of the tree
 * @index: index of node in tree (0 for root )
 * @size: size of tree
 *
 * Description: max heap must be a complete tree and the value of the root
 * node must be maximum among all values in the tree and this should be true
 * recursively
 *
 * Return: 0 if not max heap otherwise 1
 */
int is_max_heap(binary_tree_t *root, size_t index, size_t size)
{
	if (!root)
		return (1);
	if (!is_complete(root, index, size))
		return (0);
	if ((root->left && root->left->n > root->n)
			|| (root->right && root->right->n > root->n))
		return (0);
	return (is_max_heap(root->left, index, size) &&
			is_max_heap(root->right, index, size));
}

/**
 * is_complete - check if a binary tree is complete
 * @root: ptr to root node
 * @index: index of tree node (in an array)
 * @size: size of tree
 *
 * Description: if a tree is not leftmost, one node position will
 * be empty (left) so the right node will have an index >= size of
 * array, indicating one empty slot
 *
 * Return: 1 if complete 0 otherwise
 */
int is_complete(binary_tree_t *root, size_t index, size_t size)
{
	if (!root)
		return (1);
	if (index >= size)
		return (0);
	return (is_complete(root->left, (2 * index) + 1, size) &&
			is_complete(root->right, (2 * index) + 2, size));
}

/**
 * tree_size - find number of nodes in a tree
 * @tree: ptr to root node
 *
 * Return: size of tree
 */
size_t tree_size(binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (tree_size(tree->left) +
			tree_size(tree->right) + 1);
}
