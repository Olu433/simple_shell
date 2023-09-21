#ifndef SHELL_H
#define SHELL_H

/*standard library*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/*main shell functions*/
int start_shell(int ac, char **av, char **env);
char *get_input(char **av);
char **input_tokenizer(char *input, char **av);
int tokens_number(char *input);
void execute_commands(char **tokens, char **av, char **env);
int get_accessable_path(char **tokens, char **env);
char *_getenv(char **env, char *command);
void print_env(char **env);
void free_arr(char **arr);
int custom_commands(char **tokens, char **env);
void exit_shell(char **tokens);

/*utility functions*/
int _strlen(char *line);
int _strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2, size_t len);
char *_strcat(char *dest, const char *src);
void _print(int status, char **av, char *message);
void print_error(int status, char **av, char *command);

#endif /*SHELL_H*/
