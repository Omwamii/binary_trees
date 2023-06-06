#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a left-rotation on tree
 * @tree: ptr to the root node
 *
 * Return: ptr to the new root node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root, *pops;

	if (!tree || tree->left)
		return (NULL);

	pops = tree->parent;
	new_root = tree->left;
	tree->left = new_root->right;
	if (new_root->right)
		new_root->right->parent = tree;
	new_root->parent = pops;
	new_root->right = tree;
	tree->parent = new_root;
	if (pops)
	{
		/* adjust original parent whether left or right sub-tree */
		if (pops->left == tree)
			pops->left = new_root;
		else
			pops->right = new_root;
	}
	return (new_root);
}
