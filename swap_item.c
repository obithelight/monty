#include "monty.h"

/**
 * swap_item - swaps the top two elements of the stack
 * @top: pointer to the top element
 * @item: line number of opcode
 */
void swap_item(stack_t **top, unsigned int item)
{
	stack_t *ptr;

	if ((!*top) || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", item);
		fclose(coach.link);
		free(coach.line_info);
		freelist(*top);
		exit(EXIT_FAILURE);
	}
	ptr = *top;
	ptr->prev = ptr->next;

	if ((*top)->next->next == NULL)
		ptr->next = NULL;
	else
	{
		ptr->next = ptr->next->next;
		ptr->next->prev = *top;
	}
	*top = ptr->prev;
	(*top)->prev = NULL;
	(*top)->next = ptr;
}
