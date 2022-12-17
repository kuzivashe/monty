#include "monty.h"

/**
  * op_push - adds an element into a stack
  * @stack: the stack
  * @line_number: location of error in code
  * Return: nothing(void)
  */
void op_push(stack_t **stack, unsigned line_number)
{
	int val, m = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			m++;
		for (; bus.arg[m] != '\0'; m++)
		{
			if (bus.arg[m] > 57 || bus.arg[m] < 48)
					flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(bus.file);
			free(bus.content);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage push integer\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	val = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(stack, val);
	else
		addqueue(stack, val);
}
/**	if (top == LIMIT - 1)
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
}*/
