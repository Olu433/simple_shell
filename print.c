#include "shell.h"


/**
 * _print - to print on screen depend on status
 *
 * @status: state(0,1,2).
 * @av: arg values.
 * @message: message to print.
 *
 * Return: void.
 */

void _print(int status, char **av, char *message)
{
	write(status, av[0], _strlen(av[0]));
	write(status, message, _strlen(message));
}


/**
 * print_error - to print on error for exe.
 *
 * @status: state(0,1,2).
 * @av: arg values.
 * @command: faild command.
 *
 * Return: void.
 */
void print_error(int status, char **av, char *command)
{
	/*./hsh: 1: ./lolol: not found*/
	 write(status, av[0], _strlen(av[0]));
	 write(status, ": 1: ", 5);
	 write(status, command,  _strlen(command));
	 write(status, ": not found\n", _strlen(": not found\n"));
}
