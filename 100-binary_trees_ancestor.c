#include "binary_trees.h"

binary_tree_t *find_ancestor(binary_tree_t *root, int n1, int n2);
/**
 * binary_trees_ancestor - finds the lowest common ancestor of 2 nodes
 * @first: ptr to first node
 * @second: ptr to second node
 *
 * Return: ptr to lowest common ancestor or NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *root, *tmp, *tmp2, *test;

	if (!first || !second)
		return (NULL);

	tmp = (binary_tree_t *)first;
	while (tmp)
	{
		root = tmp;
		tmp = tmp->parent;
	}
	tmp2 = (binary_tree_t *)second;
	while (tmp2)
	{
		test = tmp2;
		tmp2 = tmp->parent;
	}

	/* check if nodes are in the same tree */
	if (root != test)
		return (NULL);
	return (find_ancestor(root, first->n, second->n));
}

/**
 * find_ancestor - find common ancestor recursively
 * @root: ptr to root node
 * @n1: value of first node
 * @n2: value of second node
 *
 * Return: ptr to the common ancestor
 */
binary_tree_t *find_ancestor(binary_tree_t *root, int n1, int n2)
{
	binary_tree_t *l_ancestor, *r_ancestor;

	if (!root)
		return (NULL);
	if (root->n == n1 || root->n == n2)
		return (root);

	l_ancestor = find_ancestor(root->left, n1, n2);
	r_ancestor = find_ancestor(root->right, n1, n2);

	if (l_ancestor && r_ancestor)
		return (root);

	return (l_ancestor ? l_ancestor : r_ancestor);
}
