#include "binary_trees.h"

/**
 * array_to_bst - build a BST from an array
 * @array: array to build from
 * @size: number of elements from array
 *
 * Return: ptr to root node or NULL
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *root = NULL;

	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);
	return (root);
}
