#include "monty.h"

int argument = 0;

bool comment_check(line_t line)
{
	if (line.content[0][0] == '#')
	{
		free(line.content);
		return (true);
	}

	return (false);
}

bool argument_check(char *token)
{
	unsigned int i;

	for (i = 0; token && token[i]; i++)
	{
		if (token[0] == '-')
			continue;
		if (token[i] <= '0' || token[i] >= '9')
			return (false);
	}

	return (true);
}

void push_check(line_t line, instruction_t ops[], unsigned int i)
{
	stack_t *stack = NULL;

	create_st(&stack);

	if (strcmp(ops[i].opcode, "push") == 0 && !argument_check(line.content[1]))
	{
		free(line.content);
		printf("L%d: usage: push integer\n", line.number);
		exit(EXIT_FAILURE);
	}
	else if (strcmp(ops[i].opcode, "push") == 0)
	{
		argument = atoi(line.content[1]);
	}
}
