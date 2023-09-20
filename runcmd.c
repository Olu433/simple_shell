#include "shell.h"

/**
 * runcmd - a function that run command
 * @rgv: rgv argument
 * @arv: arv argument
 * @envp: envp argument
 */
void runcmd(char **rgv, char **arv, char **envp)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error: Failed to fork process");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (execve(rgv[0], rgv, envp) == -1)
		{
			write(STDOUT_FILENO, arv[0], strlen(arv[0]));
			write(STDOUT_FILENO, ": Command not found\n", 20);
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
}
