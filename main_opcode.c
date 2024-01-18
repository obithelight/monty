#include "monty.h"

/**
 * main - entry point of the program
 * @a_count: argument count/number of arguments
 * @a_vector: argument vector/monty file location
 * Return: 0
 */
int main(int a_count, char **a_vector)
{
	static coach_t coach = {0, NULL, NULL, NULL};
	char *info = NULL;
	const FILE *next = NULL;
	size_t length = 0;
	ssize_t scanline;
	unsigned int x;
	stack_t *list = NULL;

	if (a_count < 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	next = fopen(a_vector[1], "r");
	coach.link = next;

	if (!next)
	{
		fprintf(stderr, "Error: Can't open file %s\n", a_vector[1]);
		exit(EXIT_FAILURE);
	}

	for (x = 0; (scanline = getline(&info, &length, next)) != -1; x++)
	/*while (scanline > 0)*/
	{
		coach.line_info = info;
			/* execute(info, &list, rollcall, next); */
		free(info);
	}
	freelist(list);
	fclose(next);
	return (0);
}
