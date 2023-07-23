#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *			order using the Insertion sort algorithm
 *
 * @list: Pointer to a pointer to the head of the list
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	sorted = *list;
	current = sorted->next;

	while (current != NULL)
	{
		next_node = current->next;
		while (current->prev != NULL && current->n < current->prev->n)
		{
			if (current->prev->prev != NULL)
				current->prev->prev->next = current;
			else
				*list = current;
			current->prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = current->prev;
			current->next = current->prev;
			current->prev = current->next->prev;
			current->next->prev = current;
			if (current->prev != NULL)
				current->prev->next = current;
			print_list(*list);
		}
		current = next_node;
	}
}
