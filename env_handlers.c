#include "shell.h"

/**
 * handleEnv - Handles the 'env' command.
 * @command: Command tokens.
 * @status: Exit status.
 * @environment: Environment variables.
 */
void handleEnv(char **command, int *status, char **environment)
{
    int i;

    for (i = 0; environment[i] != NULL; i++)
    {
        write(STDOUT_FILENO, environment[i], _strlen(environment[i]));
        write(STDOUT_FILENO, "\n", 1);
    }

    freeArray(command);
    (*status) = 0;
}

/**
 * handleExit - Handles the 'exit' command.
 * @command: Command tokens.
 * @argv: Program arguments.
 * @status: Exit status.
 * @index: Index.
 */
void handleExit(char **command, char **argv, int *status, int index)
{
    int exitWith = *status;

    if (command[1] != NULL)
    {
        if (isPositive(command[1]))
        {
            exitWith = _atoi(command[1]);
        }
        else
        {
            printErrorOfExit(argv[0], command[1], index);
            freeArray(command);
            (*status) = 2;
            return;
        }
    }

    freeArray(command);
    exit(exitWith);
}

/**
 * _handlePath - Handles the PATH environment variable.
 * @cmd: Command.
 * @environment: Environment variables.
 * Return: Full path to the command if found in PATH, NULL otherwise.
 */
char *_handlePath(char *cmd, char **environment)
{
    char *pathEnv = _getEnvironment("PATH", environment);

    if (!pathEnv)
        return NULL;

    char *pathEnvCopy = _strdup(pathEnv);
    char *directory = strtok(pathEnvCopy, ":");
    char *fullCmd = NULL;

    while (directory)
    {
        fullCmd = malloc(_strlen(directory) + _strlen(cmd) + 2);

        if (fullCmd)
        {
            _strcpy(fullCmd, directory);
            _strcat(fullCmd, "/");
            _strcat(fullCmd, cmd);

            struct stat state;
            if (stat(fullCmd, &state) == 0)
            {
                free(pathEnvCopy);
                free(pathEnv);
                return fullCmd;
            }

            free(fullCmd);
        }

        directory = strtok(NULL, ":");
    }

    free(pathEnvCopy);
    free(pathEnv);
    return NULL;
}

