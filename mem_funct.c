#include "shell.h"

/**
 * _calloc - Allocates memory for an array of nmemb elements of size bytes.
 * @nmemb: Number of elements of the array.
 * @size: Size in bytes of the element type.
 * Return: Pointer to the allocated memory, or NULL if it fails.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *s;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	s = malloc(nmemb * size);
	if (s == NULL)
		return (NULL);

	for (i = 0; i < (size * nmemb); i++)
		s[i] = 0;
	return (s);
}
