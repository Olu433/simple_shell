#include "shell.h"

/**
 * isPositive - checks if number is positive or not
 * @str: string
 * Return: 0 if positive or 1 if negative
 */

int isPositive(char *str)
{
	int i;

	if (!str)
	{
		return (0);
	}
	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
	}
	return (1);
}

/**
 * _atoi - converts a string to an integer
 * @str: string
 * Return: integer
 */
int _atoi(char *str)
{
	int i, num = 0;

	for (i = 0; str[i]; i++)
	{
		num *= 10;
		num += str[i] - '0';
	}
	return (num);
}

/**
 * _getEnvironment - gets the value of an environment variable
 * @variable: the name of the environment variable
 * @environment: the environment
 * Return: the value of the environment variable
 */

char *_getEnvironment(char *variable, char **environment)
{
	char *tmp, *key, *value, *env;
	int i;

	for (i = 0; environment[i]; i++)
	{
		tmp = _strdup(environment[i]);
		key = strtok(tmp, "=");
		if (_strcmp(key, variable) == 0)
		{
			value = strtok(NULL, "\n");
			env = _strdup(value);
			free(tmp), tmp = NULL;
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}

/**
 * tokenize - splits a string into words
 * @line str: the input string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **tokenize(char *line)
{
	char *token = NULL, *temp = NULL;
	char **tokens = NULL;
	int i = 0, j = 0;

	if (!line)
	{
		return (NULL);
	};
	temp = _strdup(line);
	token = strtok(temp, WHITESPACE);
	if (token == NULL)
	{
		free(line), line = NULL;
		free(temp), temp = NULL;
		return (NULL);
	}
	while (token)
	{
		i++;
		token = strtok(NULL, WHITESPACE);
	}
	free(temp), temp = NULL;

	tokens = malloc(sizeof(char *) * (i + 1));
	if (!tokens)
	{
		free(line), line = NULL;
		return (NULL);
	}
	token = strtok(line, WHITESPACE);
	while (token)
	{
		tokens[j] = _strdup(token);
		token = strtok(NULL, WHITESPACE);
		j++;
	}
	free(line), line = NULL;
	tokens[j] = NULL;
	return (tokens);
}

/**
 * readline - reads a line of text from STDIN
 * Return: string
 */

char *readline(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
	read = getline(&line, &len, stdin);

	if (read == -1)
	{
		free(line), line = NULL;
	}

	return (line);
}
