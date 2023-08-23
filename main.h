#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

#define BUFSIZE 64		/* Constant buffer size for tokenizers */
#define DELIM_I " \t\n" /* Delimiters for the hsh_tokenizer */
#define DELIM_P ":"		/* Delimiter for the tokenizer_path */

/**
 * struct choose_builtin - Structure for built-in commands
 * @name_builtin: Name of the built-in command
 * @func_builtin: Pointer to the function for the built-in command
 */
typedef struct choose_builtin
{
	char *name_builtin;
	int (*func_builtin)(char **, char *, int *);
} choose_builtins_t;

/* External variable to access the environment list */
extern char **environ;

/* Built-in functions */
int hsh_cd(char **args, char *input_stdin, int *exit_status);
int hsh_setenv(char **args, char *input_stdin, int *exit_status);
int hsh_unsetenv(char **args, char *input_stdin, int *exit_status);
int hsh_env(char **args, char *input_stdin, int *exit_status);
int hsh_exit(char **args, char *input_stdin, int *exit_status);

/* Main function */
int main(int argc __attribute__((unused)),
		 char **argv __attribute__((unused)));

/* Tokenizers and validator */
char **hsh_tokenizer(char *input);
char **tokenizer_path(char *input);
char *validate_input(char **arguments, char **argv);
int validate_spaces(char *input);

/* Executors */
int hsh_execute(char **arguments, char **argv, int *exit_status);
int hsh_execute_builtins(char **args, char *input_stdin,
						 char **argv, int *exit_status);



/* Helper functions */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *str_concat(char *s1, char *s2);

#endif
