#include "main.h"

/**
 * hsh_tokenizer - Split the input string into an array of arguments (tokens)
 * @input: String from input (main function)
 * Return: Pointer to the array of tokens
 */
char **hsh_tokenizer(char *input)
{
	int buffer = BUFSIZE, newBuffer = 0, position = 0;
	char **backup_tokens = NULL;
	char **tokens = NULL, *token = NULL;

	/* Allocate memory for the array of tokens */
	tokens = malloc(buffer * sizeof(char *));
	if (tokens == NULL)
	{
		fprintf(stderr, "memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	/* Tokenize the input string, checking for DELIM and replace them with \0 */
	token = strtok(input, DELIM_I);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		/* Reallocate the array of tokens if necessary */
		if (position >= buffer)
		{
			newBuffer = BUFSIZE * 2;
			backup_tokens = tokens;
			tokens = _realloc(tokens, buffer, newBuffer * sizeof(char *));
			if (tokens == NULL)
			{
				free(tokens);
				free(backup_tokens);
				exit(EXIT_FAILURE);
				free(backup_tokens);
			}
		}
		/* Continue processing the input string after memory reallocation */
		token = strtok(NULL, DELIM_I);
	}
	tokens[position] = NULL;
	return (tokens);
}

/*  comments for the tokenizer_path and validate_input functions... */

/**
 *  @input: String from imput
 * validate_spaces - Validate spaces, tabs, and line breaks
 * Return: 0 if no spaces, tabs, or line breaks are found
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
