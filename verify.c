#include "monty.h"

int argument = 0;

/**
 * comment_check - checks if line is a comment
 * @line: struct containing line contents and line number
 *
 * Return: true if comment, else false
 */
bool comment_check(line_t line)
{
	if (line.content[0][0] == '#')
	{
		free(line.content);
		return (true);
	}

	return (false);
}

/**
 * argument_check - verifies argument is valid
 * @token: the argument to be checked
 *
 * Return: true if valid argument, else false
 */
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

/**
 * push_check - check if push opcode is being used and sets global
 * argument variable if true
 * @line: struct containing line contents and line number
 * @ops: array containing opcode and function structs
 * @i: index of element in 'ops' array
 *
 * Return: Nothing.
 */
void push_check(line_t line, instruction_t ops[], unsigned int i)
{
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
