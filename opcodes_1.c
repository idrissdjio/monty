#include "monty.h"

void push(stack_t **stack, unsigned int nline)
{
	stack_t *new;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", nline);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	new->next = *stack;
	new->prev = NULL;
	new->n = data.data_n;
}

void pall(stack_t **stack, unsigned int nline)
{
	stack_t *temp;
	(void)nline;

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

void create_st(stack_t **stack)
{
	stack_t *new = NULL;

	if (stack == NULL)
		exit(EXIT_FAILURE);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->next = NULL;
	new->n = data.data_n;
	new->prev = NULL;
	*stack = new;
}
