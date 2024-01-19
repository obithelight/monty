#include "monty.h"

/**
 * swap_item - swaps the top two elements of the stack
 * @top: pointer to the top element
 * @item: line number of opcode
 */
void swap_item(stack_t **top, unsigned int item)
{
	stack_t *temp, *ptr;

	if ((*top) == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", item);
		freelist(*top);
		exit(EXIT_FAILURE);
	}

	temp = *top;
	ptr = temp->next;
	temp = temp->next;
	ptr = *top;
	*top = temp;

	free(ptr);
	free(temp);
}
