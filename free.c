#include "shell.h"

/**
 * free_arr - Frees a dynamically allocated 2D array.
 *
 * @arr: The 2D array to free.
 *
 * Return: void.
 */

void free_arr(char **arr)
{
    int i = 0;

    if (arr == NULL)
        return; // Avoid freeing a NULL pointer.

    while (arr[i] != NULL)
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

