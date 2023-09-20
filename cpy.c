#include "shell.h"

/**
 * _strcpy - copy a string
 * @dest: destination string argument
 * @src: source string argument
 * Return: copied string
 */
char *_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';

    return dest;
}

