#include "main.h"

/**
 * hsh_cd - Change directory
 * @args: Array of tokens
 * @input_stdin: Input from stdin
 * @exit_status: Exit status
 * Return: 1 (success)
 */
int hsh_cd(char **args, char *input_stdin, int *exit_status)
{
	int change_status;
	char previous_directory[128];

	/* Get the current working directory and save it */
	getcwd(previous_directory, sizeof(previous_directory));

	(void)input_stdin;
	(void)exit_status;

	/* Handle different cases for changing directory */
	if (args[1] == NULL)
		change_status = chdir(getenv("HOME"));
	else if (strcmp(args[1], "-") == 0)
		change_status = chdir(getenv("OLDPWD"));
	else if (strcmp(args[1], "~") == 0)
		change_status = chdir(getenv("HOME"));
	else
		change_status = chdir(args[1]);

	if (change_status == -1)
		perror("cd error");

	setenv("OLDPWD", previous_directory, 1);
	setenv("PWD", getcwd(previous_directory, sizeof(previous_directory)), 1);
	return 1;
}

/**
 * hsh_setenv - Change or add an environment variable
 * @args: Array of tokens from input
 * @input_stdin: Input from stdin
 * @exit_status: Exit status
 * Return: Return 1 if the function is used, 0 otherwise.
 */
int hsh_setenv(char **args, char *input_stdin, int *exit_status)
{
	int num_tokens = 0;

	(void)input_stdin;
	(void)exit_status;

	while (args[num_tokens] != NULL)
	{
		num_tokens++;
	}

	/* Check for the correct number of tokens */
	if (num_tokens == 3)
		setenv(args[1], args[2], 1);
	else if (num_tokens != 3)
		fprintf(stderr, "Try using \"setenv [KEY] [VALUE]\"\n");

	return 1;
}

/**
 * hsh_unsetenv - Delete an environment variable from the environment
 * @args: Array of tokens from input
 * @input_stdin: Input from stdin
 * @exit_status: Exit status
 * Return: Return 1 if the function is used, 0 otherwise.
 */
int hsh_unsetenv(char **args, char *input_stdin, int *exit_status)
{
	int num_tokens = 0;

	(void)input_stdin;
	(void)exit_status;

	while (args[num_tokens] != NULL)
	{
		num_tokens++;
	}

	if (num_tokens == 2)
		unsetenv(args[1]);
	else if (num_tokens != 2)
		fprintf(stderr, "Try using \"unsetenv [KEY]\"\n");

	return 1;
}

/**
 * hsh_env - Function that prints environment variables
 * @args: Arguments
 * @input_stdin: Input from stdin
 * @exit_status: Exit status
 * Return: Always 1 (success)
 */
int hsh_env(char **args, char *input_stdin, int *exit_status)
{
	int i = 0;

	(void)args;
	(void)input_stdin;
	(void)exit_status;

	if (environ[i] == NULL)
	{
		printf("%s", "The built-in env is empty");
		return 1;
	}
	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);

	return 1;
}

/**
 * hsh_exit - Built-in exit function
 * @args: Arguments
 * @input_stdin: Input from stdin
 * @exit_status: Exit status
 * Return: Exit success
 */
int hsh_exit(char **args, char *input_stdin, int *exit_status)
{
	int exit_code = 0;

	(void)args;
	(void)input_stdin;
	(void)exit_status;

	if (args[1] == NULL)
	{
		free(args);
		free(input_stdin);
		exit(*exit_status);
	}
	if (args[2] != NULL)
	{
		fprintf(stderr, "exit: too many arguments\n");
		return 0;
	}
	exit_code = atoi(args[1]);
	free(args);
	free(input_stdin);
	exit(exit_code);
}
