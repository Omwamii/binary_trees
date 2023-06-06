#include "binary_trees.h"
#define MAX_SIZE 50

binary_tree_t **create_queue(int *front, int *rear);
binary_tree_t *de_queue(binary_tree_t **queue, int *front);
void en_queue(binary_tree_t **queue, int *rear, binary_tree_t *new_node);
/**
 * binary_tree_levelorder - traverse tree using level-order
 * @tree: ptr to root node
 * @func: function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int rear, front;
	binary_tree_t **queue, *tmp;

	if (!tree || !func)
		return;
	queue = create_queue(&front, &rear);
	tmp = (binary_tree_t *)tree;
	while (tmp)
	{
		(*func)(tmp->n);

		/* enqueue left child */
		if (tmp->left)
			en_queue(queue, &rear, tmp->left);
		/* enqueue right child */
		if (tmp->right)
			en_queue(queue, &rear, tmp->right);
		tmp = de_queue(queue, &front);
	}
	free(queue);
}

/**
 * create_queue - creates a queue for level traversal
 * @front: ptr to front of queue
 * @rear: ptr to rear of queue
 *
 * Return: ptr to queue
 */
binary_tree_t **create_queue(int *front, int *rear)
{
	int i;
	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * MAX_SIZE);
	*front = *rear = 0;

	for (i = 0; i < MAX_SIZE; i++)
		queue[i] = NULL;

	return (queue);
}

/**
 * de_queue - remove item from queue
 * @queue: ptr to queue array
 * @front: ptr to front of queue array
 *
 * Return: dequeued item
 */
binary_tree_t *de_queue(binary_tree_t **queue, int *front)
{
	(*front)++;
	return (queue[*front - 1]);
}

/**
 * en_queue - add item to queue
 * @queue: ptr to queue array
 * @rear: ptr to rear of queue
 * @new_node: ptr to node to add to queue
 */
void en_queue(binary_tree_t **queue, int *rear, binary_tree_t *new_node)
{
	queue[*rear] = new_node;
	(*rear)++;
}
