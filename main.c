#include "shell.h"

int main(void)
{
    char *input_buffer = NULL;
    size_t buffer_size = 0;

    while (1)
    {
        write(STDOUT_FILENO, "$ ", 2);
        getline(&input_buffer, &buffer_size, stdin);
        // Your code to process the user's input goes here
    }
    return (0);
}
