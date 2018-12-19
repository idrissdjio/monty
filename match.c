#include "monty.h"

void (*get_op_func(line_t line))(stack_t **, unsigned int)
{
	unsigned int i;
	instruction_t ops[] = {
/*
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
*/
		{NULL, NULL}
	};

	if (comment_check(line))
		return (NULL);
/*		return (nop); */

	while (ops[i].opcode)
	{
		if (strcmp(ops[i].opcode, line.content[0]) == 0)
		{
			push_check(line);
			free(line.content);
			return(ops[i].f);
		}

		i++;
	}

	printf("L%d: unknown instruction %s\n", line.number, line.content[0]);
	free(line.content);
	exit(EXIT_FAILURE);
}
