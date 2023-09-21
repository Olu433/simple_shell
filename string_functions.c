#include "shell.h"

/**
 * _strcat - concatinate two strings
 *
 * @dest: first string and have the final result.
 * @src: string that we need to add.
 *
 * Return: the new string.
 */
char *_strcat(char *dest, const char *src)
{
	char *dest_temp = dest;
	const char *src_temp = src;

	while (*dest_temp != '\0')
		dest_temp++;

	while (*src_temp != '\0')
	{
		*dest_temp++ = *src_temp++;
	}
	*dest_temp = '\0';

	return (dest);
}

/**
 * _strcmp - compare two strings.
 *
 * @s1: first string
 * @s2: second string
 * @len: length to compare in
 *
 * Return: 0 in match -1 else.
 *
 */
int _strcmp(char *s1, char *s2, size_t len)
{
	size_t i = 0;

	for (i = 0 ; s1[i] && s2[i] && i < len ; i++)
	{
		if (s1[i] != s2[i])
		{
			return (-1);
		}
	}

	if (i == len)
		return (0);

	return (-1);
}

/**
 * _strcpy - return string copy.
 *
 * @dest: string that we need to copy in.
 * @src: string to copy from.
 *
 * Return: 0 on fail, 1 on sccess
 */
int _strcpy(char *dest, char *src)
{
	int len = 0;

	if (src == NULL || dest == NULL)
		return (0);

	while (src[len])
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';

	return (1);
}

/**
 * _strlen - return string len.
 *
 * @line: string that we need it's len.
 *
 * Return: strlen of string.
 */
int _strlen(char *line)
{
	int len = 0;

	if (line == NULL)
		return (0);

	while (line[len])
		len++;

	return (len);
}
