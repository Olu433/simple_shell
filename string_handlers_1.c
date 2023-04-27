#include "header.h"
/**
 * _putchar - function that writes the character to stdout
 * @c: The character to print
 * Return: character to standard output
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _puts - function that prints a string
 * @str: pointer to string
 * Return: void
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
/**
 * _strncpy - function that copies a string
 * @dest: destination string
 * @src: source string
 * @n: number of charaters to be copied
 * Return: copied strings
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n && *(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	while (i < n)
	{
		*(dest + i) = '\0';
		i++;
	}
	return (dest);
}
/**
 * _strlen - function that counts the length of a string
 * @s: string input
 * Return: length of string
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)

