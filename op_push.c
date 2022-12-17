#include "monty.h"

/**
  * op_push - adds an element into a stack
  * @element: element added into the stack
  * Return: nothing(void)
  */
void op_push(const char *element)
{
	int val;

	if (top == LIMIT - 1)
	{
		printf("Stack Overflow\n");
		exit(EXIT_FAILURE);
	}

	stack[top] = *element;

	if (top != LIMIT - 1)
	{
		val = atoi(element);
		if (val != *element || *element > 1)
		{
			printf("L%d: contains an error\n",
					((__LINE__)));
			exit(EXIT_FAILURE);
		}
	}
	top++;
}
