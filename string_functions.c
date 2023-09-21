#include "shell.h"

/**
 * _strlen - Get the length of a string.
 * @str: The string to measure.
 * Return: The length of the string.
 */
int _strlen(char *str)
{
    int length = 0;

    while (str[length] != '\0')
    {
        length++;
    }
    return (length);
}

/**
 * _strcat - Concatenate two strings.
 * @dest: The destination string.
 * @src: The source string to append.
 * Return: The concatenated string (dest).
 */
char *_strcat(char *dest, const char *src)
{
    int dest_len = _strlen(dest);
    int i;

    for (i = 0; src[i] != '\0'; i++)
    {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + i] = '\0';
    return dest;
}

/**
 * _strcpy - Copy a string.
 * @dest: The destination buffer.
 * @src: The source string to copy.
 * Return: A pointer to the destination buffer (dest).
 */
char *_strcpy(char *dest, const char *src)
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

/**
 * _strdup - Duplicate a string.
 * @str: The string to duplicate.
 * Return: A pointer to the duplicated string, or NULL on failure.
 */
char *_strdup(const char *str)
{
    int len = _strlen(str);
    char *dup_str = malloc(len + 1);

    if (dup_str == NULL)
    {
        return NULL; // Memory allocation failed.
    }

    _strcpy(dup_str, str);
    return dup_str;
}

/**
 * _strcmp - Compare two strings.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * Return: 0 if equal, positive if s1 > s2, negative if s1 < s2.
 */
int _strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

