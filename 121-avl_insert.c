#include "binary_trees.h"

bst_t *find_parent(bst_t *node, int value);
avl_t *find_imbalanced_node(avl_t *node);
/**
 * avl_insert - insert into AVL tree
 * @tree: ptr to ptr to root node
 * @value: value to store in node to be inserted
 *
 * Return: ptr to created node, NULL on fail
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	bst_t *pops, *root, *new_node, *node;
	int bl;

	if (!tree)
		return (NULL);
	root = *tree;
	pops = find_parent(root, value);
	new_node = (avl_t *)binary_tree_node(pops, value);
	if (!new_node)
		return (NULL);
	if (pops)
	{
		if (!pops->left && pops->n > value)
			pops->left = new_node;
		else
			pops->right = new_node;
	}
	else
	{
		if (!root)
			*tree = new_node;
		else
		{
			free(new_node);
			return (NULL); /* duplicate value found */
		}
	}
	node = find_imbalanced_node(new_node->parent); /* new node is bal */
	bl = binary_tree_balance((const binary_tree_t *)node);
	if (node)
	{
		if (bl > 1)
		{
			if (value < node->left->n) /* LL insertion */
				binary_tree_rotate_right((binary_tree_t *)node);
			else if (value > node->left->n) /* LR insertion */
			{
				binary_tree_rotate_left((binary_tree_t *)node->left);
				binary_tree_rotate_right((binary_tree_t *)node);
			}
		}
		else /* balance < -1 */
		{
			if (value > node->right->n) /* RR insertion */
				binary_tree_rotate_left((binary_tree_t *)node);
			else if (value < node->right->n) /* RL insertion */
			{
				binary_tree_rotate_right((binary_tree_t *)node->right);
				binary_tree_rotate_left((binary_tree_t *)node);
			}
		}
	}
	if (node && !(node->parent->parent)) /* new root after rotate */
		*tree = node->parent;
	return (new_node);
}

/**
 * find_imbalanced_node - find the first imbalanced node
 * @node: first parent of inserted node
 *
 * Return: ptr to imbalanced node or null if none
 */
avl_t *find_imbalanced_node(avl_t *node)
{
	if (!node)
		return (NULL);
	if (binary_tree_balance((const binary_tree_t *)node) < -1 ||
			binary_tree_balance((const binary_tree_t *)node) > 1)
		return (node);
	return (find_imbalanced_node(node->parent));
}
/**
 * find_parent - recursively find appropriate parent
 * @node: root node of subtree
 * @value: value of node to insert
 *
 * Return: parent node
 */
bst_t *find_parent(bst_t *node, int value)
{
	if (!node || node->n == value)
		return (NULL);
	if ((!node->left && node->n > value) ||
			(!node->right && node->n < value))
		return (node);
	if (value > node->n)
		return (find_parent(node->right, value));
	if (value < node->n)
		return (find_parent(node->left, value));
	return (node);
}
