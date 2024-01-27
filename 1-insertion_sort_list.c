#include "sort.h"

/**
 * swap_node - Swap between two nodes in a listint_t doubly-linked list.
 * @head: A head-pointer to the doubly-linked list.
 * @n1: A first-node pointer to the first node to swap.
 * @n2: The second-node pointer node to swap.
 */
void swap_node(listint_t **head, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*head = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - function sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A head pointer of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iterator, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iterator = (*list)->next; iterator != NULL; iterator = tmp)
	{
		tmp = iterator->next;
		insert = iterator->prev;
		while (insert != NULL && iterator->n < insert->n)
		{
			swap_node(list, &insert, iterator);
			print_list((const listint_t *)*list);
		}
	}
}
