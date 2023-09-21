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

/* Utility Functions */
void freeArray(char **arr);
void printError(char *name, char *cmd, int index);
void printExitError(char *name, char *cmd, int index);
char *_intToAscii();
void reverseStr(char *string, int length);
int isPositive(char *str);
int _atoi(char *str);

/* Utility Functions (utils2) */
char *_getEnvironment(char *variable, char **environment);
char **tokenize(char *line);
char *readline(void);

/*  String Manipulation Functions */
int _strlen(char *string);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);

/* Execute Function */
int _execute(char **cmd, char **argv, char **environment, int index);

/* Handlers */
char *_handlePath(char *cmd, char **environment);
void handleExit(char **command, char **argv, int *status, int index);
void handleBuiltIn(char **command, char **argv, int *status, int index, char **environment);
void handleEnv(char **command, int *status, char **environment);

/* Custom StringTokenizer */
char *myStrtok(char *str, const char *delim);

/* Custom Getline Function */
ssize_t myGetline(char **linePtr, size_t *n, FILE *stream);

/* Check Built-In Command */
int isBuiltIn(char *command);

#endif /* SHELL_H */
