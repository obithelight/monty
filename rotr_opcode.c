#include "monty.h"

/**
 * rotr_item - swaps the top two elements of the stack
 * @top: pointer to the top element
 * @item: line number of opcode
 */
void rotr_item(stack_t **top, unsigned int item)
{
	stack_t *temp;
	int count;

	(void)item;
	if ((*top) == NULL || (*top)->next == NULL)
	{
		return;
	}

	temp = *top;
	for (count = 0; temp; count++)
	{
		if (!temp->next)
		{
			break;
		}
		temp = temp->next;
	}
	temp->next = *top;
	temp->prev->next = NULL;
	(*top)->prev = temp;
	(*top) = temp;
	temp->prev = NULL;
}
