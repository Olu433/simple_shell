#include "shell.h"

/**
 * handleEnv - handles the env command
 * @command: command
 * @status: status to exit with
 * @enviornment: environment
 * Return: void
 */

void handleEnv(char **command, int *status, char **enviornment)
{
	int i;

	for (i = 0; enviornment[i]; i++)
	{
		write(STDOUT_FILENO, enviornment[i], _strlen(enviornment[i]));
		write(STDOUT_FILENO, "\n", 1);
	}

	freeArray(command);
	(*status) = 0;
}

/**
 * handleExit - handle exit command
 * @command: command to free
 * @status: to exit with
 * @argv: arguments
 * @index: index
 * Return: void
 */

void handleExit(char **command, char **argv, int *status, int index)
{
	int exitWith = *status;

	if (command[1] && isPositive(command[1]))
	{
		exitWith = _atoi(command[1]);
	}
	else if (command[1] && !isPositive(command[1]))
	{
		printErrorOfExit(argv[0], command[1], index);
		freeArray(command);
		(*status) = 2;
		return;
	}
	freeArray(command);
	exit(exitWith);
}

/**
 * _handlePath - handles the path
 * @cmd: command
 * @environment: environment
 * Return: path
 */

char *_handlePath(char *cmd, char **environment)
{
	char *pathEnv, *pathEnvCopy, *fullCmd, *directory;
	struct stat state;
	int i;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &state) == 0)
				return (_strdup(cmd));
			return (NULL);
		}
	}
	pathEnv = _getEnvironment("PATH", environment);
	if (!pathEnv)
		return (NULL);

	pathEnvCopy = _strdup(pathEnv), directory = strtok(pathEnvCopy, ":");
	while (directory)
	{
		fullCmd = malloc(_strlen(directory) + _strlen(cmd) + 2);
		if (fullCmd)
		{
			_strcpy(fullCmd, directory), _strcat(fullCmd, "/"), _strcat(fullCmd, cmd);
			if (stat(fullCmd, &state) == 0)
			{
				free(pathEnvCopy);
				free(pathEnv);
				return (fullCmd);
			}
			free(fullCmd);
		}
		directory = strtok(NULL, ":");
	}
	free(pathEnvCopy);
	free(pathEnv);
	return (NULL);
}
