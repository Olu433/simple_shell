#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdbool.h>

#define MAX_C 10

/**
 * struct denum - Structure that contains variables
 * @cnt: Line count
 */
typedef struct denum
{
    int cnt;
} denum;

/**
 * @brief Display the shell prompt.
 *
 * @param arv Array of command-line arguments.
 * @param envp Array of environment variables.
 * @param flg Boolean flag.
 */
void prompt(char **arv, char **envp, bool flg);

/**
 * @brief Compare two strings.
 *
 * @param s1 First string to compare.
 * @param s2 Second string to compare.
 * @return 0 if equal, a positive value if s1 > s2, or a negative value if s1 < s2.
 */
int _strcmp(char *s1, char *s2);

/**
 * @brief Concatenate two strings.
 *
 * @param dest Destination string to append to.
 * @param src Source string to append.
 * @return Pointer to the concatenated string.
 */
char *_strcat(char *dest, char *src);

/**
 * @brief Handle the path for a command.
 *
 * @param rgv Array of command arguments.
 * @param cmd Command to handle.
 * @return Path to the executable or NULL if not found.
 */
char *handle_path(char **rgv, char *cmd);

/**
 * @brief Copy a string from source to destination.
 *
 * @param dest Destination string.
 * @param src Source string.
 * @return Pointer to the destination string.
 */
char *_strcpy(char *dest, char *src);

/**
 * @brief Get the length of a string.
 *
 * @param s Input string.
 * @return Length of the string.
 */
int _strlen(char *s);

/**
 * @brief Handle the exit command.
 *
 * @param cmd Command to handle.
 */
void handle_exit(char *cmd);

/**
 * @brief Run a command.
 *
 * @param rgv Array of command arguments.
 * @param arv Array of command-line arguments.
 * @param envp Array of environment variables.
 */
void runcmd(char **rgv, char **arv, char **envp);

/**
 * @brief Trim leading and trailing whitespace from a string.
 *
 * @param cmd Input string to trim.
 * @return Pointer to the trimmed string.
 */
char *trim(char *cmd);

/**
 * @brief Copy a substring from source to destination with a specified length.
 *
 * @param dest Destination string.
 * @param src Source string.
 * @param n Length of the substring to copy.
 * @return Pointer to the destination string.
 */
char *_strncpy(char *dest, char *src, int n);

/**
 * @brief Get the path of an executable command.
 *
 * @param cmd Command to search for in the PATH.
 * @return Path to the executable or NULL if not found.
 */
char *get_path(char *cmd);

/**
 * @brief Get the value of an environment variable by name.
 *
 * @param name Name of the environment variable.
 * @return Value of the environment variable or NULL if not found.
 */
char *_getenv(char *name);

/**
 * @brief Tokenize an environment variable.
 *
 * @param path Environment variable to tokenize.
 * @return Array of tokens.
 */
char **tokenize_env(char *path);

extern char **environ;

/**
 * @brief Handle error reporting.
 *
 * @param n Pointer to a denum structure containing the line count.
 * @param arv Array of command-line arguments.
 * @param cmd Command associated with the error.
 */
void geterror(denum *n, char **arv, char *cmd);

#endif /* SHELL_H */
