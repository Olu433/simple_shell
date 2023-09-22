#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @string: string
 * Return: length
 */

int _strlen(char *string)
{
	int i;

	for (i = 0; string[i] != '\0'; i++)
	{
		;
	}
	return (i);
}

/**
 * _strcat - concatenate two strings
 * @dest: first string
 * @src: second string
 * Return: concatenated string
 */

char *_strcat(char *dest, char *src)
{
	int len = 0;
	int j = 0;

	while (dest[len] != '\0')
	{
		len++;
	}
	while (src[j] != '\0')
	{
		dest[len + j] = src[j];
		j++;
	}
	dest[len + j] = '\0';
	return (dest);
}

/**
 * *_strcpy - copies the string pointed
 * @dest: buffer
 * @src: string to be pointed by src
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	char *dest_start = dest;

	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (dest_start);
}

/**
 * _strdup - Duplicate a string
 * @str: The string to duplicate
 * Return: duplicated string, or NULL
 */

char *_strdup(const char *str)
{
	char *ptr;
	int i, len = 0;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		len++;
		str++;
	}
	str = str - len;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (i = 0; i <= len; i++)
	{
		ptr[i] = str[i];
	}
	return (ptr);
}

/**
 * _strcmp - Compare two strings
 * @s1: first string
 * @s2: second string
 * Return: compared strings
 */

int _strcmp(char *s1, char *s2)
{
	int i;
	int dif = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			dif = s1[i] - s2[i];
			break;
		}
	}
	return (dif);
}
