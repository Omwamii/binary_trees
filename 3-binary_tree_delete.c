#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: pointer to tree root node
 *
 */
void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *tmp, *parent;

	if (!tree)
		return;

	tmp = tree;
	while (tmp)
	{
		if (tmp->left)
		{
			tmp = tmp->left;
			continue;
		}
		if (tmp->right)
		{
			tmp = tmp->right;
			continue;
		}
		parent = tmp->parent;

		/* for binary, remove links */
		if (parent && parent->left == tmp)
			parent->left = NULL;
		else if (parent && parent->right == tmp)
			parent->right = NULL;
		free(tmp);
		tmp = parent;
	}
}
