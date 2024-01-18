#include "monty.h"

/**
 * pop_item - removes the top element from stack
 * @top: pointer to the top element
 * @item: the element to be removed
 */
void pop_item(stack_t **top, unsigned int item)
{
	stack_t *ptr;
	(void)item;

	ptr = *top;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", item);
		fclose(coach.link);
		free(coach.line_info);
		freelist(*top);
		exit(EXIT_FAILURE);
	}
	else
	{
		*top = (*top)->next;
		free(ptr);
	}
}
