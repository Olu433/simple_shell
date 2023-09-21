#include "shell.h"

/**
 * _strlen - Returns the length of a string.
 * @s: String
 * Return: Length of the string.
 */

int _strlen(char *s)
{
    int i;

    for (i = 0; s[i] != '\0'; ++i)
    {
    }

    return (i);
}

/**
 * *_strncpy - copies a string from src to dest,
 * at most, n bytes of src are copied.
 * @dest: destination string.
 * @src: source string.
 * @n: most number of bytes it will copy.
 * Return: A char string.
 */

char *_strncpy(char *dest, char *src, int n)
{

    int i;

    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    for (; i < n; i++)
        dest[i] = '\0';

    return (dest);
}

/**
  * _strdup - Returns a pointer to a new string,
  * which is a duplicate of the string str.
  * @str: pointer string
  * Return: NULL if str = NULL or a pointer to the duplicated string
  **/

char *_strdup(char *str)
{
    int i = 0, j = 0;
    char *a = NULL;

    if (str == NULL)
        return (NULL);
    while (str[i] != '\0')
    {
        i++;
    }
    a = _calloc((i + 1), sizeof(char));
    if (a != NULL)
    {
        for (; str[j]; j++)
            a[j] = str[j];
        a[j] = '\0';
    }
    else
        return (NULL);
    return (a);
}

/**
 * *_strcat - concatenates two strings
 *
 * @dest: .
 * @src: .
 *
 * Return: A char string.
 */

char *_strcat(char *dest, char *src)
{
    int i, j;

    for (i = 0; dest[i] != '\0'; i++)
    {
    }

    for (j = 0; src[j] != '\0'; i++, j++)
        dest[i] = src[j];

    dest[i] = '\0';

    return (dest);
}

/**
 * *_strcmp - compares two strings
 *
 * @s1:  first string .
 * @s2: Second string.
 *
 * Return: the number of characters difference between s1 and s2.
 */

int _strcmp(char *s1, char *s2)
{

    for (; (*s1 != '\0' && *s2 != '\0') && *s1 == *s2; s1++, s2++)
    {
    }
    if (*s1 == *s2)
        return (0);
    else
        return (*s1 - *s2);
}

