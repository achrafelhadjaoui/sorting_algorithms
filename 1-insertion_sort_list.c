#include "sort.h"

/**
 * insertion_sort_list - a function that sort a doubly linked list
 * of integers in ascending order using the insertion sort algo
 * @list: a doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *tmp;

	if (!list || !(*list) || !(*list)->next)
		return;

	ptr = (*list)->next;
	while (ptr != NULL)
	{
		tmp = ptr;
		ptr = ptr->next;
		while (tmp->prev && tmp->n < tmp->prev->n)
		{
			tmp->prev->next = tmp->next;
			tmp->next = tmp->prev;
			tmp->prev = tmp->next->prev;
			tmp->next->prev = tmp;
			if (tmp->prev)
				tmp->prev->next = tmp;
			else
				*list = tmp;
			if (tmp->next->next)
				tmp->next->next->prev = tmp->next;
			print_list(*list);
		}
	}
}
