#include "shell.h"

// Function to calculate the length of an integer
int calculateLength(int number)
{
	unsigned int num;
	int length = 1;

	if (number < 0)
	{
		length++;
		num = number * -1;
	}
	else
	{
		num = number;
	}
	while (num > 9)
	{
		length++;
		num = num / 10;
	}

	return (length);
}

// Function to convert an integer to a string
char *integerToString(int number)
{
	char *buffer;
	size_t  num;
	int length = calculateLength(number);

	buffer = malloc(length + 1);
	if (!buffer)
	{
		return (NULL);
	}
	buffer[length] = '\0';
	if (number < 0)
	{
		num = number * -1;
		*buffer = '-';
	}
	else
		num = number;
	length--;

	do {
		*(buffer + length) = (num % 10) + '0';
		num /= 10;
		length--;
	} while (num > 0);
	
	return (buffer);
}

// Function to generate an error message when a command is not found
void generateError(denum *denumPointer, char **argv, char *command)
{
	int length;
	char *errorMessage, *countString;

	countString = integerToString(denumPointer->count);
	length = _strlen(argv[0]) + _strlen(command) + _strlen(countString) + 17;
	errorMessage = malloc(length);
	if (!errorMessage)
	{
		return;
	}
	
    _strcpy(errorMessage, argv[0]);
    _strcat(errorMessage, ": ");
    _strcat(errorMessage, countString);
    _strcat(errorMessage, ": ");
    _strcat(errorMessage, command);
    _strcat(errorMessage, ": not found\n");
    _strcat(errorMessage, "\0");
    
    write(STDOUT_FILENO, errorMessage, length);
    
    free(errorMessage);
}

