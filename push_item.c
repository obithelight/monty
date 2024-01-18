#include "monty.h"

/**
 * monty_push_opcode - pushes an element to the stack
 * @head_node: head pointer of the stack
 * @line_no: monty bytecode-file line number
 */
void monty_push_opcode(stack_t **head_node, unsigned int line_no)
{
	int num, loop = 0, checkflag = 0;

	if (coach.argv)
	{
		if (coach.argv[0] == '-')
			loop++;

		while (coach.argv[loop])
		{
			if (coach.argv[loop] < '0' || coach.argv[loop] > '9')
			{
				checkflag = 1;
				break;
			}
			loop++;
		}
		if (checkflag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_no);
			free(coach.argv);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_no);
		free(coach.argv);
		exit(EXIT_FAILURE);
	}
	num = atoi(coach.argv);
	free(coach.argv);

	if (coach.status == 0)

		add_node_to_stack(head_node, num);
	else
		add_node_to_queue(head_node, num);
}
