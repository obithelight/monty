#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <ctype.h>
#include <fcntl.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct coach_s - takes in needed variables, files, arguments, etc
 * @status: flag change from stack <-> queue
 * @link: monty pointer
 * @line_info: content of line
 * @argv: argument vector
 *
 * Description: carries values through the program
 */
typedef struct coach_s
{
	int status;
	FILE *link;
	char *line_info;
	char *argv;
}  coach_t;
extern coach_t coach;

void monty_push_opcode(stack_t **head_node, unsigned int line_no);
void monty_pall_opcode(stack_t **head_node, unsigned int line_no);
void monty_pint_opcode(stack_t **front, unsigned int line_no);
void add_node_to_stack(stack_t **front, int data);
void add_node_to_queue(stack_t **front, int data);
void freelist(stack_t *head);
void top_queue(stack_t **coin, unsigned int num);
void top_stack(stack_t **coin, unsigned int num);
int exectask(stack_t **top, FILE *montyfile, unsigned int count,
char *line_content);
void swap_item(stack_t **top, unsigned int item);
void add_item(stack_t **top, unsigned int item);
void pop_item(stack_t **top, unsigned int item);
void rotr_item(stack_t **top, __attribute__((unused)) unsigned int counter);





char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);





void nop_item(stack_t **head, unsigned int counter);
void sub_item(stack_t **head, unsigned int counter);
void div_item(stack_t **head, unsigned int counter);
void mul_item(stack_t **head, unsigned int counter);
void mod_item(stack_t **head, unsigned int counter);


void pchar_item(stack_t **top, unsigned int counter);
void pstr_item(stack_t **top, unsigned int counter);
void rotl_item(stack_t **top, unsigned int counter);






#endif /*MONTY_H*/
