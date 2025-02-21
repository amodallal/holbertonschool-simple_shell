#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 64

extern char **environ;

char **parse_input(char *line);
int execute_command(char **args, char *shell_name, char **envp);
void handle_exit(char **args);
void free_args(char **args);

#endif /* SHELL_H */

