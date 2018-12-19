#include "monty.h"

/* TODO - check if double pointer manipulation of struct is valid */
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

void parsefile(FILE *file)
{
	size_t size = 0;
	char *buffer;
	stack_t *stack = NULL;
	line_t line;

	line.number = 0;
	line.content = NULL;
	/* create_st(&stack); */

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
