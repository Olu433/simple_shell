#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

// Constants
#define WHITESPACE " \t\n"

// Utility Functions
void freeArray(char **arr);
void printError(char *program, char *command, int index);
void printErrorOfExit(char *program, char *command, int index);
char *intToAscii(int number);
void reverseString(char *string, int length);
int isPositiveInteger(char *str);
int stringToInteger(char *str);

// Utility Functions (utils2)
int isPositiveInteger(char *str);
int stringToInteger(char *str);
char *getEnvironmentVariable(char *variable, char **environment);
char **tokenizeInputLine(char *line);
char *readUserInputLine(void);

// String Manipulation Functions
int stringLength(char *string);
char *stringConcatenate(char *dest, char *src);
char *stringCopy(char *dest, char *src);
char *stringDuplicate(const char *str);
int stringCompare(char *s1, char *s2);

// Execution Function
int executeCommand(char **cmd, char **argv, char **environment, int index);

// Handler Functions
char *handlePath(char *cmd, char **environment);
void handleExitCommand(char **command, char **argv, int *status, int index);
void handleBuiltInCommand(char **command, char **argv, int *status, int index, char **environment);
void handleEnvCommand(char **command, int *status, char **environment);

// Tokenization Function
char *customTokenizer(char *str, const char *delimiters);

// Custom Input Reading Function
ssize_t customGetline(char **linePtr, size_t *n, FILE *stream);

// Built-In Command Detection
int isBuiltInCommand(char *command);

#endif
