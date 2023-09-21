#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

#define strtok_delim " \n\r\a\t"

extern char **environ;
int str_to_array(char *cmd_line, int count, char **argv);
int _exec(char **cmd_list, int i, char *cmd_line, int count, char **argv);
void command_not_found(int i, char **cmd_list, int count, char **argv);
int _strlen(char *s);
char *_strncpy(char *dest, char *src, int n);
char *_strdup(char *str);
char *_path(char *command);
char *directory(char *temporal_dir, char *command);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
void *_calloc(unsigned int nmemb, unsigned int size);
void a_exit(char **text, int i, char *cmd_line, int exit_status);
void _env(void);
void signal_handler(int signal);
int _putchar(char c);
void print_number(int n);

#endif
