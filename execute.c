#include "shell.h"

/**
 * execute_commands - to execute comands.
 *
 * @tokens: arguments to execute.
 * @av: argument values.
 * @env: environment.
 *
 * Return: void.
 */

void execute_commands(char **tokens, char **av, char **env)
{
	pid_t child_pid;
	int stat;

	if (tokens == NULL || tokens[0] == NULL)
		return;

	if (tokens[0][0] != '.' && tokens[0][0] != '/')
	{
		if (custom_commands(tokens, env))
			return;
		else if (!get_accessable_path(tokens, env))
		{
			print_execute_error(2, av, tokens[0]);
			return;
		}
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		_print(2, av, " :error in creating process\n");
		return;
	}

	if (child_pid == 0)
	{
		if (execve(tokens[0], tokens, env) == -1)
		{
			print_execute_error(2, av, tokens[0]);
			free_arr(tokens);
			exit(1);
		}
	}
	else
	{
		do {
			waitpid(child_pid, &stat, WUNTRACED);
		} while (!WIFEXITED(stat) && !WIFSIGNALED(stat));
	}
}
