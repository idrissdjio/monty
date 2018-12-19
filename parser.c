#include "monty.h"

/**
 * main - opens a monty script file for parsing
 * @ac: count of arguments
 * @av: array of arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int ac, char *av[])
{
	FILE *file;

	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(av[1], "r");
	if (!file)
	{
		printf("Error: Can't open file %s\n", av[1]);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
