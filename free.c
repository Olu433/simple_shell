#include "shell.h"

/**
 * freeArray - free an array of tokens
 * @arr: array to get freedom
 * Return: void
 */

void freeArray(char **arr)
{
	int i;

	if (!arr)
	{
		return;
	};
	for (i = 0; arr[i]; i++)
	{
		free(arr[i]), arr[i] = NULL;
	};
	free(arr), arr = NULL;
}

/**
 * printError - returns an error message
 * @name: name of the command
 * @cmd: command
 * @indexNum: index
 * Return: void
 */
void printError(char *name, char *cmd, int indexNum)
{
	char *index, errMessage[] = ": not found\n";

	index = _intToAscii(indexNum);
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, errMessage, _strlen(errMessage));

	free(index);
}
/**
 * printErrorOfExit - returns an error message for exit
 * @name: name of the command
 * @cmd: command
 * @indexNum: index
 * Return: void
 */
void printErrorOfExit(char *name, char *cmd, int indexNum)
{
	char *index, errMessage[] = ": exit: Illegal number: ";

	index = _intToAscii(indexNum);
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, errMessage, _strlen(errMessage));
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, "\n", 1);
	free(index);
}

/**
 * _intToAscii - converts an integer to ascii
 * @n: integer
 * Return: ascii
 */
char *_intToAscii(int n)
{
	char buffer[25];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[i] = '\0';
	reverseStr(buffer, i);

	return (_strdup(buffer));
}

/**
 * reverseStr - reverses a string
 * @string: string
 * @length: length
 * Return: void
 */
void reverseStr(char *string, int length)
{
	char temp;
	int start = 0;
	int end = length - 1;

	while (start < end)
	{
		temp = string[start];
		string[start] = string[end];
		string[end] = temp;
		start++;
		end--;
	}
}
