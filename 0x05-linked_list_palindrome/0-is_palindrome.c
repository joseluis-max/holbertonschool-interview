#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * is_palindrome - checks is a singly linked list is a palindrome
 * @head: single linked list
 * Return: 1 if is a palindrome, otherwise 0
 */
int is_palindrome(listint_t **head)
{
	listint_t *rabbit = *head;
	listint_t *turtle = *head;
	listint_t *copy = *head;
	int *stack;
	int size = 0;
	int j = 0;

	if (head == NULL || (*head) == NULL)
		return (1);
	while (copy->next != NULL)
	{
		size += 1;
		copy = copy->next;
	}
	if (size == 1)
		return (1);
	stack = (int *)malloc(sizeof(int) * size);
	while (rabbit != NULL)
	{
		stack[j] = turtle->n;
		j++;
		if (turtle->next == NULL)
			return (1);
		turtle = turtle->next;
		if (rabbit->next == NULL)
			break;
		rabbit = rabbit->next;
		rabbit = rabbit->next;
	}
	while (turtle->next != NULL)
	{
		j--;
		if (turtle->n == stack[j])
			turtle = turtle->next;
		else
		{
			free(stack);
			return (0);
		}
	}
	free(stack);
	if (rabbit != NULL)
		return (0);
	return (1);
}
