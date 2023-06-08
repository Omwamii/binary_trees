#include "binary_trees.h"

bst_t *delete_node(bst_t *root, int value);
bst_t *min_val_node(bst_t *root);
/**
 * bst_remove - removes a node from a BST
 * @root: root node of tree
 * @value: value of node to remove
 *
 * Return: root of the new node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (!root)
		return (NULL);
	return (delete_node(root, value));
}

/**
 * delete_node - delete node from tree
 * @root: root node of tree
 * @value: value of node to delete
 *
 * Return: new root node
 */
bst_t *delete_node(bst_t *root, int value)
{
	bst_t *tmp;

	if (!root)
		return (root);
	if (value < root->n)
		root->left = delete_node(root->left, value);
	else if (value > root->n)
		root->right = delete_node(root->right, value);
	else
	{
		/* node has one or no child */
		if (!root->left)
		{
			tmp = root->right;
			free(root);
			return (tmp);
		}
		else if (!root->right)
		{
			tmp = root->left;
			free(root);
			return (tmp);
		}

		/* node has 2 children */
		tmp = min_val_node(root->right);

		root->n = tmp->n;

		root->right = delete_node(root->right, tmp->n);
	}
	return (root);
}

/**
 * min_val_node - find the min value node
 * @root: root node
 *
 * Return: node with the minimum value
 */
bst_t *min_val_node(bst_t *root)
{
	bst_t *current = root;

	while (current && current->left)
		current = current->left;
	return (current);
}
