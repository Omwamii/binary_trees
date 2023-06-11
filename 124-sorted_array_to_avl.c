#include "binary_trees.h"

avl_t *find_parent(avl_t *node, int value);
void populate(int *array1, int *array2,  int low, int high, int size);
/**
 * sorted_array_to_avl - make an AVL tree from sorted array
 * @array: ptr to first element of array
 * @size: size of array
 *
 * Return: root of tree or null
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL, *parent, *new_node;
	int *tree_array;
	size_t i;

	if (!array || size <= 0)
		return (NULL);
	if (size == 1)
		return (binary_tree_node(NULL, array[0])); /* one node */
	tree_array = malloc(sizeof(int) * size);
	if (!tree_array)
		return (NULL);
	populate(array, tree_array, 0, size - 1, (int)size);
	for (i = 0; i < size; i++)
	{
		if (!root)
			root = binary_tree_node(NULL, tree_array[i]);
		else
		{
			parent = find_parent(root, tree_array[i]);
			new_node = binary_tree_node(parent, tree_array[i]);
			if (tree_array[i] < parent->n)
				parent->left = new_node;
			else
				parent->right = new_node;
		}
	}
	free(tree_array);
	return (root);
}

/**
 * populate - populates an array with the correct order to avoid
 * rotating an AVL tree when inserting from a sorted array
 * @array1: sorted array to inster from
 * @array2: array to populate
 * @low: low bound
 * @high: high bound
 * @size: size of array1
 */
void populate(int *array1, int *array2,  int low, int high, int size)
{
	static int i;
	int medium;

	if (low == high)
	{
		array2[i] = array1[high];
		return;
	}
	medium = (high + low) / 2;
	array2[i++] = array1[medium];
	populate(array1, array2, low, medium, size);
	populate(array1, array2, medium + 1, high, size);
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
