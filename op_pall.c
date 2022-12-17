#include "monty.h"

/**
  * op_pall - prints all the values of the stack
  * starting from the top of the stack
  * @i: index of the stack
  * Return: nothing(void)
  */
void op_pall(stack_t **stack, unsigned int n)
{
	stack_t *h;
	(void)n;

	h = *stack;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
/*	if (top)
	{
		printf("Stack Underflow\n");
		exit(EXIT_FAILURE);
	}
	else if (top > 0)
	{
		printf("The elements of the stack are:\n");

		for (i = top; i >= 0; i--)
		{
			printf("%d\n", stack[i]);
		}
	}
}*/
