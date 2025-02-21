#include "shell.h"

/**
 * parse_input - Tokenizes the user input
 * @line: The input string
 * 
 * Return: Tokenized arguments or NULL
 */
char **parse_input(char *line)
{
	char **args;
	char *token;
	int i = 0;

	args = malloc(sizeof(char *) * MAX_ARGS);
	if (!args)
		return (NULL);
	
	token = strtok(line, " \t\n");
	while (token)
	{
		args[i++] = token;
		token = strtok(NULL, " \t\n");
	}
	args[i] = NULL;

	return (args);
}

