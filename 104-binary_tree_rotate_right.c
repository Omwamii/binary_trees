#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a left-rotation on tree
 * @tree: ptr to the root node
 *
 * Return: ptr to the new root node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (!tree)
		return (NULL);
	if (!tree->left && !tree->right)
		return (NULL);

	new_root = tree->left;
	tree->left = new_root->right;
	new_root->parent = tree->parent;
	new_root->right = tree;
	tree->parent = new_root;
	return (new_root);
}
