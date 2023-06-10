#include "binary_trees.h"

/**
 * array_to_avl - build a BST from an array
 * @array: array to build from
 * @size: array size
 *
 * Return: ptr to root node or NULL
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i;
	avl_t *root = NULL;

	for (i = 0; i < size; i++)
		avl_insert(&root, array[i]);
	return (root);
}
