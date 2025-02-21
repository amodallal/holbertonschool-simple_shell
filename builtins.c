#include "shell.h"

/**
 * handle_exit - Handles the exit command
 * @args: The arguments array
 */
void handle_exit(char **args)
{
	free_args(args);
	exit(0);
}

/**
 * free_args - Frees allocated arguments array
 * @args: The arguments array
 */
void free_args(char **args)
{
	if (args)
		free(args);
}

