#include "monty.h"

/**
 * pint - prints the value at the top of stack
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
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
/**
 * pop - removes the top element of stack
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void pop(stack_t **stack, unsigned int nline)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", nline);
		exit(EXIT_FAILURE);
	}
	/* if stack is more than 1 node, else free entire thing */
	if ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}
/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void swap(stack_t **stack, unsigned int nline)
{
	int temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", nline);
		free(stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
/**
 * add - adds the top two elements together
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void add(stack_t **stack, unsigned int nline)
{
	int res = 0;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", nline);
		free(stack);
		exit(EXIT_FAILURE);
	}

	res += (*stack)->n;
	res += (*stack)->next->n;

	/* pop current, then override current n*/
	pop(stack, nline);
	(*stack)->n = res;
}
