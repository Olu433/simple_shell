#include "shell.h"

/**
 * isBuiltIn - checks if the command is a built-in
 * @command: command
 * Return: 0 or 1
 */

int isBuiltIn(char *command)
{
	int i;

	char *builtIns[] = {
		"exit", "cd", "env", "setenv", NULL};

	for (i = 0; builtIns[i]; i++)
	{
		if (_strcmp(builtIns[i], command) == 0)
		{
			return (1);
		}
	}

	return (0);
}

void handleBuiltIn(
	char **command, char **argv, int *status, int index, char **enviornment)
{
	(void)index;
	if (_strcmp(command[0], "exit") == 0)
	{
		handleExit(command, argv, status, index);
	}
	else if (_strcmp(command[0], "env") == 0)
	{
		handleEnv(command, status, enviornment);
	}
}
