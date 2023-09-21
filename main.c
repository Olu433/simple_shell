#include "shell.h"

int main(__attribute__((unused)) int ac, char **av)
{
    char *line = NULL;
    size_t len = 0;
    int i = 1, count = 0;

    while (i != -1)
    {
        count++;
        signal(SIGINT, signal_handler);
        if (isatty(STDIN_FILENO) == 1)
            write(STDOUT_FILENO, "$ ", 2);
        i = getline(&line, &len, stdin);
        if (i < 0)
        {
            free(line);
            exit(0);
        }
        str_to_array(line, count, av);
        free(line);
        line = NULL;
    }
    return (0);
}
