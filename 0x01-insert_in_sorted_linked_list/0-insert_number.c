#include <stdlib.h>
#include "lists.h"

/** insert_node - Insert node in sorted linked list
 * @head: Head linked list
 * @number: new node integer value
 * Return: new node address or NULL
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *node;
    listint_t *copy = *head;

    node = malloc(sizeof(listint_t));
    if (node == NULL)
        return (NULL);
    node->n = number;
    node->next = NULL;

    if (*head == NULL)
    {
        *head = node;
        return (node);
    }

    if ((*head)->n >= node->n)
    {
        node->next = *head;
        *head = node;
        return (node);
    }

    copy = *head;

    while (copy->next)
    {
        if (node->n <= copy->next->n)
        {
            node->next = copy->next;
            copy->next = node;
            return (node);
        }
        copy = copy->next;
    }

    copy->next = node;
    return (node);
}
