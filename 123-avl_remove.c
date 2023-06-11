#include "binary_trees.h"

void balance_tree(avl_t *node, int bal, int value);
avl_t *search(avl_t *node, int value);
avl_t *min_val_node(avl_t *root);
/**
 * avl_remove - removes a node from a BST
 * @root: root node of tree
 * @value: value of node to remove
 *
 * Return: root of the new node
 */
avl_t *avl_remove(bst_t *root, int value)
{
	avl_t *remove, *parent, *successor, *ancestor, *imbalance;
	int bal;

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
	/* balance the tree after removing */
	imbalance = find_imbalanced_node(parent); /* imbalanced node */
	bal = binary_tree_balance(imbalance);
	balance_tree(imbalance, bal, value);
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

/**
 * balance_tree - balances the tree after operations
 * @node: imbalanced node
 * @bal: balance factor of the node
 * @value: value of previous deleted node
 */
void balance_tree(avl_t *node, int bal, int value)
{
	if (!node || bal == 0 || bal == 1 || bal == -1)
		return;
	if (bal > 1)
	{
		if (value > node->left->n) /* LL insertion */
			binary_tree_rotate_right((binary_tree_t *)node);
		else if (value < node->left->n) /* LR insertion */
		{
			binary_tree_rotate_left((binary_tree_t *)node->left);
			binary_tree_rotate_right((binary_tree_t *)node);
		}
	}
	else /* balance < -1 */
	{
		if (value < node->right->n) /* RR insertion */
			binary_tree_rotate_left((binary_tree_t *)node);
		else if (value > node->right->n) /* RL insertion */
		{
			binary_tree_rotate_right((binary_tree_t *)node->right);
			binary_tree_rotate_left((binary_tree_t *)node);
		}
	}
}
