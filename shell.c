#include "shell.h"

/**
 * main - main function
 * @arc: len argument
 * @arv: arv argument by user
 * @envp: envp argument env
 * Return: 0
 */
int main(int arc, char **arv, char **envp)
{
	bool interactive = (arc == 1 && isatty(STDIN_FILENO));

	prompt(arv, envp, interactive);
	return (0);
}

/**
 * prompt - function to display the prompt and get user input
 * @arv: arv argument by user
 * @envp: envp argument env
 * @interactive: flag to check if the shell is interactive
 */
void prompt(char **arv, char **envp, bool interactive)
{
	char *line = NULL;
	size_t len = 0;

	while (interactive)
	{
		printf("$ ");
		if (getline(&line, &len, stdin) == -1)
		{
			if (errno == EINTR)
				continue;
			else
				break;
		}
		execute(line, arv, envp);
	}
	free(line);
}

/**
 * execute - function to execute the user command
 * @line: line entered by the user at the prompt
 * @arv: arv argument by user
 * @envp: envp argument env
 */
void execute(char *line, char **arv, char **envp)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		// Child process
		if (execve(line, arv, envp) == -1)
			perror("Error");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		// Error forking
		perror("Error");
	}
	else
	{
		// Parent process
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

