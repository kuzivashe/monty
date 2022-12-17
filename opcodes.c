#include "monty.h"

/**
  * op_push - adds an element into a stack
  * @stack: the stack
  * @line_number: location of error in code
  * Return: nothing(void)
  */
void op_push(stack_t **stack, unsigned int line_number)
{
	register int num;
	char *params = strtok(NULL, "\n");

	if (check_string(params) == -1)
	{
		fprintf(stderr, "L%u: usage push integer\n", line_number);
		cleaner();
		exit(EXIT_FAILURE);
	}
	num = atoi(params);
	if (args.order == 1)
	{
		addnode(stack, num);
	}
	else
	{
		addnode_end(stack, num);
	}
}

/**
  * op_pall - prints all the values of the stack
  * starting from the top of the stack
  * @stack: doubly linked list
  * @line_number: the line
  * Return: nothing(void)
  */
void op_pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	print_dlistint(*stack);
}
