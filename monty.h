#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

#define LIMIT 10

/**
  * struct stack_s - doubly linked list representation
  * of a stack or queue
  * @n: integer
  * @prev: points to the previous element of the stack
  * or queue
  * @next: points to the next element of the stack or
  * queue
  *
  * Description: doubly linked list node structure
  * for Stack, Queues, LIFO, FIFO
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
  * for stacks, queues, LIFO, FIFO
  */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
  * struct arguments - values to be accessed by various functions
  * @argv: name of the executable
  * @counter: counts the number of lines
  * @file: pointer to monty file
  * @line: input line
  * @stack: doubly linked linked list
  * @order: FIFO, LIFO
  */
typedef struct arguments
{
	char **argv;
	FILE *file;
	ssize_t *content;
	int order;
	char *line;
	stack_t *stack;
} args_t;
extern args_t args;
/*int stack[LIMIT];
int top = -1;*/
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);

stack_t *addnode(stack_t **head, const int n);
stack_t *addnode_end(stack_t **head, const int n);
void cleaner(void);

void free_stack(stack_t *stack);
void op_pint(int i);
void op_pop(int element);
void op_swap(int a, int b);
void op_add(int a, int b);
void op_nop(void);

/* linked list functions */
void free_dlistint(stack_t *head);
size_t print_dlistint(const stack_t *h);
int check_string(char *s);
/* datastruct-interpreter  */
void stack(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
