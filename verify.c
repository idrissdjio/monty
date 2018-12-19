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

void push_check(line_t line)
{
	stack_t *stack = NULL;

	if (strcmp(ops[i], "push") == 0 && !argument_check(line.content[1]))
	{
		free(line.content);
		printf("L%d: usage: push integer\n", line.number);
		exit(EXIT_FAILURE);
	}
	else if (strcmp(ops[i].opcode, "push") == 0)
	{
		argument = atoi(line.content[1]);
		create_st(stack);
	}
}
