#include <stddef.h>
#include "lists.h"


/**
 * check_cycle - check if there is a cycle in a linked list
 * @list: linked list head
 * Return: int 0 or 1
 */
int check_cycle(listint_t *list)
{
	listint_t *turtle = list;
	listint_t *rabbit = list;

	while (rabbit != NULL && rabbit->next != NULL)
	{
		turtle = turtle->next;
		rabbit = rabbit->next->next;
		if (rabbit == turtle)
			return (1);
	}

	return (0);
}
