#include "monty.h"

/**
 * parseline - tokenizes a line of text, storing it in line struct
 * @line: struct containing line contents and line number
 * @buffer: string of text read from script file
 *
 * Return: Nothing
 */
void parseline(line_t *line, char *buffer)
{
	unsigned int i;
	char *token = NULL;

	line->content = malloc(sizeof(char *) * 3);
	if (!line->content)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	token = strtok(buffer, " '\n'");
	for (i = 0; token && i < 2; i++)
	{
		line->content[i] = token;
		token = strtok(NULL, " \n");
	}

	line->content[i] = NULL;
}

/**
 * parsefile - reads and parses file one line at a time
 * @file: the script to be read
 *
 * Return: Nothing
 */
void parsefile(FILE *file)
{
	size_t size = 0;
	char *buffer = NULL;
	stack_t *stack = NULL;
	line_t line;

	line.number = 0;
	line.content = NULL;

	while (getline(&buffer, &size, file) != -1)
	{
		line.number++;
		parseline(&line, buffer);
		if (line.content)
			get_op_func(line)(&stack, line.number);
	}

	fclose(file);
	free(buffer);
	free_stack(&stack);
}
