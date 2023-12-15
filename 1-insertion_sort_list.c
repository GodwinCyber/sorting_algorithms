#include "sort.h"

/**
 * insertion_sort_list -  sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to pointer of the head of the list
 * Return: return theblist ech tie it swap with two element
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;
	while (curr != NULL)
	{
		prev = curr->prev;
		next = curr->next;
		while (prev != NULL && curr->n < prev->n)
		{
			prev->next = next;
			if (next != NULL)
				next->prev = prev;
			curr->prev = prev->prev;
			curr->next = prev;
			if (prev->prev != NULL)
				prev->prev->next = curr;
			else
				*list = curr;
			prev->prev = curr;
			print_list(*list);
			prev = curr->prev;
			next = curr->next;
		}
		curr =  next;
	}
}
