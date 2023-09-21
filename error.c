#include "shell.h"

/**
 * command_not_found - copies a string.
 *
 * @i: pointer to destination string.
 * @cmd_list: pointer to source string.
 * @count: line counter.
 * @argv: argument vector.
 * Return: a char string.
 */
void command_not_found(int i, char **cmd_list, int count, char **argv)
{
    int l = 0;

    write(STDOUT_FILENO, argv[0], _strlen(argv[0]));
    write(STDOUT_FILENO, ": ", 2);
    print_number(count);
    write(STDOUT_FILENO, ": ", 2);
    write(STDOUT_FILENO, cmd_list[0], _strlen(cmd_list[0]));
    write(STDOUT_FILENO, ": not found\n", 12);
    while (l < i)
    {
        free(cmd_list[l]);
        l++;
    }
    free(cmd_list);
}

/**
 * print_number - function that prints an integer.
 * @n: number.
 * Return: void.
**/
void print_number(int n)
{
    unsigned int x;

    if (n < 0)
    {
        x = -n;
        _putchar('-');
    }
    else
    {
        x = n;
    }
    if (x / 10)
    {
        print_number(x / 10);
    }
    _putchar(x % 10 + '0');
}

/**
 * _putchar - writes the character c to stdout.
 * @c: The character to print.
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}
