#include "monty.h"

coach_t coach = {0, NULL, NULL, NULL};

/**
 * main - entry point of the program
 * @a_count: argument count/number of arguments
 * @a_vector: argument vector/monty file location
 * Return: 0
 */
int main(int a_count, char **a_vector)
{
	char *info = NULL;
	FILE *next = NULL;
	size_t length = 0;
	ssize_t scanline = 1;
	unsigned int rollcall;
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

	for (rollcall = 0; scanline > 0; rollcall++)/*while (scanline > 0)*/
	{
		scanline = getline(&info, &length, next);
		coach.line_info = info;
		/*if (scanline > 0)
			execute(info, &list, rollcall, next);*/
		free(info);
	}
	freelist(list);
	fclose(next);
	return (0);
}
