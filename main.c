#include "shell.h"

/**
 * main - entry point to start program
 *
 * @ac: arguments counter.
 * @av: arguments values.
 * @env: environment.
 *
 * Return: 0 on success
 */
int main(int ac, char **av, char **env)
{
	int status;

	status = start_shell(ac, av, env);

	return (status);
}
