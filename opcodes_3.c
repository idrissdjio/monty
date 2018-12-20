#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void rotl(stack_t **stack, unsigned int nline)
{
	int temp;
	stack_t *temp = *stack;
	(void)nline;

	if (stack == NULL || *stack == NULL)
	{
		nop(stack);
	}

	temp = (*stack)->n;
	printf("this number: %d\n", temp);
}
