#include "shell.h"

/**
 * main - the shell
 * @argv: arguments
 * @ac: arguments
 * @environment: environment
 * Return: 0
 */

int main(int ac, char **argv, char **environment)
{
	char *line, **tokens;
	int status = 0, indexNum = 0;
	(void)ac;

	while (1)
	{
		line = readline();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "$ ", 2);
			}
			return (status);
		}
		indexNum++;

		tokens = tokenize(line);
		if (!tokens)
		{
			continue;
		}

		if (isBuiltIn(tokens[0]))
		{
			handleBuiltIn(tokens, argv, &status, indexNum, environment);
		}
		else
		{
			status = _execute(tokens, argv, environment, indexNum);
		}
	}
}
