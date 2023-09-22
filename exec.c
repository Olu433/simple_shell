#include "shell.h"
/**
 * _execute - executes a command
 * @cmd: command
 * @argv: arguments
 * @environment: environment
 * @indexNum: index
 * Return: status
 */
int _execute(char **cmd, char **argv, char **environment, int indexNum)
{
	char *fullCmd;
	pid_t childProcess;
	int status;

	fullCmd = _handlePath(cmd[0], environment);

	if (!fullCmd)
	{
		printError(argv[0], cmd[0], indexNum);
		freeArray(cmd);
		return (127);
	}
	childProcess = fork();
	if (childProcess == 0)
	{
		if (execve(fullCmd, cmd, environment) == -1)
		{
			perror("execve");
		}
		free(fullCmd), fullCmd = NULL;
		freeArray(cmd);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (waitpid(childProcess, &status, 0) == -1)
		{
			perror("waitpid");
		}
		free(fullCmd), fullCmd = NULL;
		freeArray(cmd);
	}
	return (WEXITSTATUS(status));
}
