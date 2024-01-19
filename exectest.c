#include "monty.h"
/**
* exectask - carries out the opcode function
* @top: head linked list - stack
* @count: line_counter
* @montyfile: poiner to monty file
* @line_content: line content
* Return: 1
*/
int exectask(stack_t **top, FILE *montyfile, unsigned int count,
char *line_content)
{
	unsigned int start;
	char *temp;
	instruction_t mylist[] = {
					{"push", monty_push_opcode}, {"pall", monty_pall_opcode},
					{"pint", monty_pint_opcode}, {"stack", top_stack}, {"queue", top_queue},
					{"pop", pop_item}, {"swap", swap_item}, {"add", add_item},
				/*	{"nop", nop_item}, {"sub", sub_item}, {"div", div_item}, */
				/*	{"mul", mul_item}, {"mod", mod_item}, {"pchar", pchar_item}, */
				/*	{"pstr", pstr_item}, {"rotl", rotl_item},*/
					{"rotr", rotr_item}, {NULL, NULL}
				};
	start = 0;

	temp = strtok(line_content, " \n\t");
	if (temp[0] == '#' && temp)
		return (0);
	coach.argv = strtok(NULL, " \n\t");
	while (mylist[start].opcode && temp)
	{
		if (strcmp(temp, mylist[start].opcode) == 0)
		{	mylist[start].f(top, count);
			return (0);
		}
		start++;
	}
	if (temp && mylist[start].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, temp);
		fclose(montyfile);
		free(line_content);
		freelist(*top);
		exit(EXIT_FAILURE); }
	return (1);
}
