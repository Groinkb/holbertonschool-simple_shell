#include "main.h"

/**
 * hsh_execute - Fork process and execute a new program
 * @arguments: String of arguments (tokens)
 * @argv: Array of arguments..
 * @exit_status: Exit status
 * Return: Always 1 (success).
 */
int hsh_execute(char **arguments, char **argv, int *exit_status)
{
	char *new_arguments;
	pid_t pid;
	int status;

	new_arguments = validate_input(arguments, argv);
	if (strcmp(new_arguments, "Fail access") == 0)
		return (1);

	pid = fork();
	if (pid == 0)
	{
		if (execve(new_arguments, arguments, environ) == -1)
		{
			perror("execve fail");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0) /* Check if fork fails */
	{
		perror("Error forking");
		free(new_arguments);
		return (1);
	}
	else /* Parent process */
	{
		waitpid(-1, &status, 0);				/* Equivalent to wait(&status) */
		if (WIFEXITED(status))					/* Check if the child terminated normally */
			*exit_status = WEXITSTATUS(status); /* Return the exit status of the child */
		if (arguments[0][0] != '/' && arguments[0][0] != '.')
			free(new_arguments);
		return (1);
	}
	return (1);
}

/**
 * hsh_execute_builtins - Execute built-in functions or external programss
 * @args: String of arguments (token)
 * @input_stdin: String from input
 * @argv: Array of arguments
 * @exit_status: Exit status
 * Return: Status to stay (1) or exit the main loop (0)
 */
int hsh_execute_builtins(char **args, char *input_stdin,
						 char **argv, int *exit_status)
{
	int i = 0;

	choose_builtins_t options[] = {
		{"env", hsh_env},
		{"cd", hsh_cd},
		{"setenv", hsh_setenv},
		{"exit", hsh_exit},
		{"unsetenv", hsh_unsetenv},
		{NULL, NULL}};

	while (options[i].name_builtin)
	{
		if (strcmp(options[i].name_builtin, args[0]) == 0)
		{
			return ((int)((*options[i].func_builtin)(args, input_stdin, exit_status)));
		}
		i++;
	}
	return (hsh_execute(args, argv, exit_status));
}
