#include "shell.h"
#include <stdio.h>

int main(void)
{
    char *text[] = {"Hello", "World"};
    char *cmd_line = "ls -l";
    int exit_status = 0;
    int i;

    /* Example usage of functions */
    i = 2; /* Number of elements in the 'text' array */

    /* Copy a string */
    char dest[100];
    _strcpy(dest, "Hello, World!");
    printf("Copied string: %s\n", dest);

    /* Allocate and clear memory */
    char *mem = (char *)_calloc(10, sizeof(char));
    printf("Allocated memory: %s\n", mem);

    /* Exit the program properly */
    a_exit(text, i, cmd_line, exit_status);

    /* Print the environment */
    _env();

    return (0);
}

