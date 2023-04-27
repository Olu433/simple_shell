#include "header.h"
/**
 * _strcpy - function that copies a string
 * @dest: destination
 * @src: source
 * Return: destination
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcat - function that concatenates two strings
 * @dest: first string
 * @src: second string
 * Return: first string + second string
 */
char *_strcat(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
}
/**
 * _strchr - function that locates character in a string
 * @s: string to be searched
 * @c: character to be located
 * Return: pointer to character
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
		{
			break;
		}
	} while (*s++);
	return (s);

