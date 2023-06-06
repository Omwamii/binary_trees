#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on tree
 * @tree: ptr to the root node
 *
 * Return: ptr to the new root node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *pops;

	if (!tree || !tree->right)
		return (NULL);

	pops = tree->parent;
	new_root = tree->right;
	tree->right = new_root->left;
	if (new_root->left)
		new_root->left->parent = tree;
	new_root->parent = pops;
	new_root->left = tree;
	tree->parent = new_root;
	if (pops)
	{
		if (pops->left == tree)
			pops->left = new_root;
		else
			pops->right = new_root;
	}
	return (new_root);
}
