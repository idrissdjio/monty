#include "monty.h"

void pint(stack_t **stack, unsigned int nline)
{
	stack_t *temp;
	(void)nline;

	temp = *stack;
	while (temp)
	{
		if (temp->prev == NULL)
			break;
		temp = temp->prev;
	}

	printf("%d\n", temp->n);
}

void pop(stack_t **stack, unsigned int nline)
{
	stack_t *temp;
	(void)nline;

	temp = *stack;
	while (temp)
	{
		if (temp->prev == NULL)
			break;
		temp = temp->prev;
	}
	printf("pop this: %d\n", temp->n);
}
