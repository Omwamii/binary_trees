#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on tree
 * @tree: ptr to the root node
 *
 * Return: ptr to the new root node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (!tree)
		return (NULL);
	if (!tree->left && !tree->right)
		return (NULL);

	new_root = tree->right;
	tree->right = new_root->left;
	new_root->parent = tree->parent;
	new_root->left = tree;
	tree->parent = new_root;
	return (new_root);
}
