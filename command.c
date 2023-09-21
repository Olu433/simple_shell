#include "shell.h"

/**
 * custom_commands - to handle things not exist in shell.
 *
 * @tokens: commands to execute.
 * @env: environment.
 *
 * Return: 1 on success, 0 on fail to found comand.
 *
 */
int custom_commands(char **tokens, char **env)
{
	if (_strcmp(tokens[0], "env", 3) == 0)
	{
		print_env(env);

		return (1);
	}
	else if (_strcmp(tokens[0], "exit", 4) == 0)
	{
		exit_shell(tokens);

		return (1);
	}

	return (0);
}
