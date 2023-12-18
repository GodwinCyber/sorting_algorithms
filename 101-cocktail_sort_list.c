#include "sort.h"

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	node1->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = node1;
	node2->prev = node1->prev;
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;
	node2->next = node1;
	node1->prev = node2;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending order
 * using the Cocktail shaker sort algorithm
 * @list: pointer to the pointer of the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *curr, *end;
	int swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	end = NULL;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		curr = *list;
		while (curr->next != end)
		{
			if (curr->n > curr->next->n)
			{
				swap_nodes(list, curr, curr->next);
				swapped = 1;
				print_list(*list);
			}
			else
				curr = curr->next;
		}
		end = curr;
		if (!swapped)
			break;
		swapped = 0;
		while (curr->prev != NULL)
		{
			if (curr->n < curr->prev->n)
			{
				swap_nodes(list, curr->prev, curr);
				swapped = 1;
				print_list(*list);
			}
			else
				curr = curr->prev;
		}
	}
}
