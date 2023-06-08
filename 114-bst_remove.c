#include "binary_trees.h"

bst_t *search(bst_t *node, int value);
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
	bst_t *remove, *parent, *successor, *ancestor;

	if (!root)
		return (NULL);
	remove = search(root, value);

	/* nothing to remove */
	if (!remove)
		return (root);
	parent = remove->parent;
	if (!remove->left && !remove->right)
	{
		if (parent)
		{
			if (parent->left == remove)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		else
			root = NULL; /* root node is removed */
		free(remove);
	}
	else if (!remove->right && remove->left)
	{
		if (parent)
		{
			if (parent->left == remove)
				parent->left = remove->left;
			else
				parent->right = remove->left;
		}
		else
			root = remove->left;
		remove->left->parent = parent;
		free(remove);
	}
	else if (!remove->left && remove->right)
	{
		if (parent)
		{
			if (parent->left == remove)
				parent->left = remove->right;
			else
				parent->right = remove->right;
		}
		else
			root = remove->right;
		remove->right->parent = parent;
		free(remove);
	}
	else
	{
		successor = min_val_node(remove->right);
		ancestor = successor->parent;
		if (ancestor != remove)
			successor->parent->left = NULL; /* leftmost since its the least */
		successor->parent = parent;
		if (parent)
		{
			if (parent->left == remove)
				parent->left = successor;
			else
				parent->right = successor;
		}
		else
			root = successor;
		successor->left = remove->left;
		if (remove->right != successor)
			successor->right = remove->right;
		if (successor->right)
			successor->right->parent = successor;
		if (successor->left)
			successor->left->parent = successor;
		free(remove);
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

/**
 * search - search for node in tree
 * @node: root node
 * @value: value of node to find
 *
 * Return: ptr to the node found
 */
bst_t *search(bst_t *node, int value)
{
	if (!node)
		return (NULL);
	if (node->n == value)
		return (node);
	if (node->n > value)
		return (search(node->left, value));
	if (node->n < value)
		return (search(node->right, value));
	return (node);
}

