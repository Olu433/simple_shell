#include "shell.h"

/**
 * get_accessable_path - get path to execute commands.
 *
 * @tokens: tokens to execte.
 * @env: environment.
 *
 * Return: 1 on success 0 on fail.
 */
int get_accessable_path(char **tokens, char **env)
{
	char *path = _getenv(env, "PATH");
	char *dir, *path_copy;
	char *command;
	struct stat sb;
	int len;

	if (path == NULL)
		return (0);

	len = _strlen(path) + 1;
	path_copy = malloc(len * (sizeof(char)));
	if (path_copy == NULL)
		return (0);
	_strcpy(path_copy, path);

	dir = strtok(path_copy, ":=");
	while (dir != NULL)
	{
		command = malloc(_strlen(dir) + _strlen(tokens[0]) + 2);
		if (!command)
		{
			free(path_copy);
			return (0);
		}
		_strcpy(command, dir);
		_strcat(command, "/");
		_strcat(command, tokens[0]);
		if (stat(command, &sb) == 0)
		{
			free(tokens[0]);
			tokens[0] = command;
			free(path_copy);
			return (1);
		}
		free(command);
		dir = strtok(NULL, ":=");
	}
	free(path_copy);
	return (0);
}
