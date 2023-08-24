#include "main.h"

/**
 * hsh_tokenizer - Split the input string into a array of arguments (tokens)
 * @input: String from input (main function)
 * Return: Pointer to the array of tokens
 */
char **hsh_tokenizer(char *input)
{
	int buffer = BUFSIZE, newBuffer = 0, position = 0;
	char **tokens = NULL, *token = NULL;
	char **backup_tokens = NULL;

	/* allocate memory for the array of tokens */
	tokens = malloc(buffer * sizeof(char *));
	if (tokens == NULL)
	{
		fprintf(stderr, "memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	/* tokenize the input string, checking for DELIM and replace them with \0 */
	token = strtok(input, DELIM_I);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		/* reallocate the array of tokens*/
		if (position >= buffer)
		{
			newBuffer = BUFSIZE * 2;
			backup_tokens = tokens;
			tokens = _realloc(tokens, buffer, newBuffer * sizeof(char *));
			if (tokens == NULL)
			{
				free(backup_tokens);
				free(tokens);
				fprintf(stderr, "memory allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		/* once memory reallocation, continue processing the input string */
		token = strtok(NULL, DELIM_I);
	}
	tokens[position] = NULL;
	return (tokens);
}

/**
 * tokenizer_path - Split the environment variable PATH into an array of tokens
 * @input: Pointer to environment variable PATH
 * Return: Pointer to the array of tokens
 */
char **tokenizer_path(char *input)
{
	int buffer = BUFSIZE, newBuffer = 0, position = 0;
	char **tokens = NULL, *token = NULL;
	char **backup_tokens = NULL;

	/* allocate memory for the array of tokens */
	tokens = malloc(buffer * sizeof(char *));
	if (tokens == NULL)
	{
		fprintf(stderr, "memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	/* tokenize the PATH string, checking for DELIM and replace it with \0 */
	token = strtok(input, DELIM_P);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		/* reallocate the array of tokens if necessary*/
		if (position >= buffer)
		{
			newBuffer = BUFSIZE * 2;
			backup_tokens = tokens;
			tokens = _realloc(tokens, buffer, newBuffer * sizeof(char *));
			if (tokens == NULL)
			{
				free(backup_tokens);
				free(tokens);
				fprintf(stderr, "memory allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		/* once memory reallocation, continue processing the PATH string */
		token = strtok(NULL, DELIM_P);
	}
	/* null terminate the array of tokens */
	tokens[position] = NULL;
	return (tokens);
}

/**
 * validate_input - Validate if PATH exists
 * @arguments: String of tokens
 * @argv: String of arguments from input
 * Return: A pointer to an array of the tokenized PATH directories
 **/
char *validate_input(char **arguments, char **argv __attribute__((unused)))
{
	char *new_arguments, *first, *slash_argument = "/";
	char **tokens_path, holder_env[1024];
	int i = 0;

	if (arguments[0][0] == '/' || arguments[0][0] == '.') /*check first element */
	{
		new_arguments = arguments[0];			 /* point to the same address */
		if ((access(new_arguments, F_OK) == -1)) /* check if file exits */
		{
			fprintf(stderr, "%s: No such file or directory\n", arguments[0]);
			return ("Fail access");
		}
	}
	else
	{
		strcpy(holder_env, getenv("PATH"));		  /*get PATH and copy it to holder_env buf*/
		tokens_path = tokenizer_path(holder_env); /*tokenize PATH env*/
		while (tokens_path[i])
		{
			/* check if file exists */
			first = str_concat(slash_argument, arguments[0]);
			new_arguments = str_concat(tokens_path[i], first);
			if ((access(new_arguments, F_OK) == -1))
			{
				free(new_arguments);
				free(first);
			}
			else
			{
				free(tokens_path);
				free(first);
				return (new_arguments);
			}
			i++;
		}
		free(tokens_path);
		fprintf(stderr, "%s: 1: %s: not found\n", argv[0], arguments[0]);
		return ("Fail access");
	}
	return (new_arguments);
}

/**
 * validate_spaces - Validate spaces, tabs and line breaks
 * @input: String from input
 * Return: 0 if not find spaces, tabs or line break
 */
int validate_spaces(char *input)
{
	int i = 0, flag = 1, len = 0;

	len = strlen(input);

	while (input[i] == ' ' || input[i] == '\n' || input[i] == '\t')
		i++;

	if (i != len)
		flag = 0;
	return (flag);
}
