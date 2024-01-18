#include "monty.h"

/**
 * monty_pint_opcode - prints the top of stack
 * @front: head of stack
 * @line_no: line_number
 * Return: no return
*/
void monty_pint_opcode(stack_t *front, unsigned int line_no)
{
	if (front == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_no);
		fclose(coach.link);
		free(coach.line_info);
		freelist(front);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", front->n);
}
