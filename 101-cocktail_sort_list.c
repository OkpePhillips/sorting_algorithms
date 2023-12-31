#include "sort.h"

/**
* cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
*                      using the Cocktail shaker sort algorithm
*
* @list: Pointer to a pointer to the head of the list
*
* Return: Nothing
*/
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start = NULL;
	listint_t *end = NULL;
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	
	do
	{
		swapped = 0;
		current = *list;
		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, &current, &(current->next));
				print_list(*list);
				swapped = 1;
			}

			else
			{
				current = current->next;
			}
		}
		if (!swapped)
			break;
		end = current;
		swapped = 0;

		while (current->prev != start)
		{
			if (current->prev->n > current->n)
			{
				swap_nodes(list, &(current->prev), &current);
				print_list(*list);
				swapped = 1;
			}
			else
			{
				current = current->prev;
			}
		}
		start = current->next;
	} while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @list: Pointer to a pointer to the head of the list
 * @node1: Pointer to the first node to swap
 * @node2: Pointer to the second node to swap
 */
void swap_nodes(listint_t **list, listint_t **node1, listint_t **node2)
{
	listint_t *prev1, *prev2, *next1, *next2;

	prev1 = (*node1)->prev;
	next1 = (*node1)->next;
	prev2 = (*node2)->prev;
	next2 = (*node2)->next;

	if (prev1 != NULL)
		prev1->next = *node2;
	if (next2 != NULL)
		next2->prev = *node1;

	(*node1)->prev = prev2;
	(*node1)->next = next2;
	(*node2)->prev = prev1;
	(*node2)->next = next1;

	if (prev1 == NULL)
		*list = *node2;
	if (prev2 != NULL)
		prev2->next = *node1;
	if (next1 != NULL)
		next1->prev = *node2;
}
