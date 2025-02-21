#include "shell.h"

/**
 * main - Entry point of the shell
 * @argc: Argument count
 * @argv: Argument vector
 * @envp: Environment variables
 *
 * Return: 0 on success, or an error code
 */
int main(int argc, char **argv, char **envp)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **args;
	int status = 0;

	(void)argc;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			exit(status);
		}
		args = parse_input(line);
		if (!args || !args[0])
		{
			free(args);
			continue;
		}
		status = execute_command(args, argv[0], envp); /* ✅ Fixed */
		free(args);
	}
	free(line);
	return (status);
}

