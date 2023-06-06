#include "binary_trees.h"

unsigned int count_nodes(binary_tree_t *root);
bool is_complete(binary_tree_t *root, unsigned int index,
		unsigned int num_nodes);
/**
 * binary_tree_is_complete - find if binary tree is complete
 * @tree: pointer to the root node
 *
 * Return: 0 if tree is null, 1 if complete
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *root = (binary_tree_t *)tree;
	unsigned int num_nodes = count_nodes(root);

	if (!tree)
		return (0);

	if (is_complete(root, 0, num_nodes))
		return (1);
	return (0);
}

/**
 * count_nodes - count nodes in a tree
 * @root: ptr to root node
 *
 * Return: number of nodes counted
 */
unsigned int count_nodes(binary_tree_t *root)
{
	if (!root)
		return (0);
	return (1 + count_nodes(root->left) + count_nodes(root->right));
}

/**
 * is_complete - check if a tree is complete
 * @root: ptr to root node
 * @index: index of current node
 * @num_nodes: number of nodes in tree
 *
 * Return: true if complete else false
 */
bool is_complete(binary_tree_t *root, unsigned int index,
		unsigned int num_nodes)
{
	/* empty tree is complete */
	if (!root)
		return (true);
	/* if not leftmost, rightmost has index >= number of nodes */
	if (index >= num_nodes)
		return (false);
	return (is_complete(root->left, (2 * index) + 1, num_nodes) &&
			is_complete(root->right, (2 * index) + 2, num_nodes));
}
