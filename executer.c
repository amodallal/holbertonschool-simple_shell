#include "shell.h"

/**
 * execute_command - Executes a command
 * @args: The command arguments
 * @shell_name: The shell name (for error messages)
 * @envp: Environment variables
 *
 * Return: Exit status of the command
 */
int execute_command(char **args, char *shell_name, char **envp)
{
	pid_t pid;
	int status;

	if (strcmp(args[0], "exit") == 0)
		handle_exit(args);

	pid = fork();
	if (pid == -1)
	{
		perror(shell_name);
		return (-1);
	}
	if (pid == 0)
	{
		if (execve(args[0], args, envp) == -1)
		{
			perror(shell_name);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);

	return (WEXITSTATUS(status));
}

