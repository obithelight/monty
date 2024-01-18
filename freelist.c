#include "monty.h"

/**
 * freelist - frees memory in the linked list
 * @head: head pointer
 * Return: nothing
 */
void freelist(stack_t *head)
{
	stack_t *tail;

	tail = head;

	while (head)
	{
		tail = head->next;
		free(head);
		head = tail;
	}
}
