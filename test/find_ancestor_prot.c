#include "binary_trees.h"

binary_stack_t *ancestor_stack(binary_tree_t *target);
binary_tree_t *find_ancestor(binary_tree_t *node1, binary_tree_t *node2);
void free_stack(binary_stack_t *head);
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
	if (!first || !second)
		return (NULL);
	return (find_ancestor((binary_tree_t *)first, (binary_tree_t *)second));
}

/**
 * ancestor_stack - initialize stack for node path to root
 * @target: node to find path to root
 *
 * Return: ptr to stack head
 */
binary_stack_t *ancestor_stack(binary_tree_t *target)
{
	binary_stack_t *head = NULL, *stack, *next_node;
	binary_tree_t *tmp;

	if (!target)
		return (NULL);
	head = malloc(sizeof(binary_stack_t));
	if (!head)
		return (NULL);
	tmp = target;
	stack = head;
	while (tmp && stack)
	{
		stack->node = tmp;
		if (tmp->parent)
		{
			next_node = malloc(sizeof(binary_stack_t));
			if (!next_node)
			{
				free_stack(head);
				return (NULL);
			}
			next_node->node = NULL;
			next_node->next = NULL;
		}
		else
			next_node = NULL;
		stack->next = next_node;
		tmp = tmp->parent;
		stack = next_node;
	}
	return (head);
}

/**
 * find_ancestor - find the lowest common ancestor
 * @node1: first node
 * @node2: second node
 *
 * Return: ptr to common ancestor or NULL
 */
binary_tree_t *find_ancestor(binary_tree_t *node1, binary_tree_t *node2)
{
	binary_stack_t *head1, *head2, *tmp;
	binary_tree_t *ancestor = NULL;

	head1 = ancestor_stack(node1);
	head2 = ancestor_stack(node2);
	if (!head1)
	{
		if (!head2)
			return (NULL);
		free_stack(head2);
		return (NULL);
	}
	if (!head2)
	{
		free_stack(head1);
		return (NULL);
	}
	while (head1)
	{
		tmp = head2;
		while (tmp)
		{
			if (head1->node == tmp->node)
				ancestor = head1->node;
			if (ancestor)
				break;
			tmp = tmp->next;
		}
		if (ancestor)
			break;
		head1 = head1->next;
	}

	free_stack(head1);
	free_stack(head2);
	return (ancestor); /* no ancestor */
}

/**
 * free_stack - free ancestor list
 * @head: ptr to head of list
 *
 */
void free_stack(binary_stack_t *head)
{
	binary_stack_t *tmp, *node;

	if (!head)
		return;
	tmp = head;
	while (tmp)
	{
		node = tmp;
		tmp = node->next;
		free(node);
	}
}
