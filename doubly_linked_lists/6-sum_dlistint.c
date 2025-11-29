#include "lists.h"
#include <stdlib.h>
/**
 * sum_dlistint - returns the sum of all the data (n) in a dlistint_t list
 * @head: pointer to the head of the list
 *
 * Return: the sum of all nodes' n values, or 0 if list is empty
 */
int sum_dlistint(dlistint_t *head)
{
int sum = 0;

while (head != NULL)
{
sum += head->n;
head = head->next;
}

return (sum);
}
