#include "lists.h"
#include <stdlib.h>
/**
 * free_list - Frees a list_t list.
 * @head: Pointer to the first node of the list.
 *
 * Description: Frees all nodes and their strings in a linked list.
 */

void free_list(list_t *head)
{
list_t *temp;

while (head != NULL)
{
temp = head->next;
free(head->str);
free(head);
head = temp;
}
}
