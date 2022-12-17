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
  * struct bus_s - variables -args, file, line content
  * @arg: value
  * @file: pointer to monty file
  * @content: line content
  * @lifi: flag change stack <-> queue
  *
  * Description: carries values through the program
  */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} bus_t;
extern bus_t bus;

int stack[LIMIT];
int top = -1;
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int n);
void addnode(stack_t **stack, int n);
void addqueue(stack_t **stack, int n);
void free_stack(stack_t *stack);
void op_pint(int i);
void op_pop(int element);
void op_swap(int a, int b);
void op_add(int a, int b);
void op_nop(void);

#endif /* MONTY_H */
