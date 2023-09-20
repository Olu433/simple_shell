#include "shell.h"

/**
 * _strlen - Compute the length of a string
 * @s: The string to measure
 * Return: The length of the string
 */
int _strlen(char *s)
{
    char *p = s;

    while (*p != '\0')
    {
        p++;
    }

    return p - s;
}

