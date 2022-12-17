#include "monty.h"

/**
  * cleaner - cleans stack
  */
void cleaner(void)
{
	free_dlistint(args.stack);
	if (args.file)
	{
		fclose(args.file);
	}
}
