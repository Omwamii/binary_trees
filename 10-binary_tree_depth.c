#include "binary_trees.h"

/**
 * binary_tree_depth - find depth of node
 * @tree: pointer to the node to measure depth
 *
 * Return: 0 if tree is NULL, else height
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	binary_tree_t *root;

	if (!tree)
		return (depth);
	root = tree->parent;
	while (root)
	{
		depth++;
		root = root->parent;
	}
	return (depth);

}
