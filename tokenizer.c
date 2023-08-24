#include "main.h"

/**
 * hsh_tokenizer - Split the input string into an array of arguments (tokens)
 * @input: String from input (main function)
 * Return: Pointer to the array of tokens
 */
char **hsh_tokenizer(char *input)
{
	int buffer = BUFSIZE, newBuffer = 0, position = 0;
	char **tokens = NULL, *token = NULL;
	char **backup_tokens = NULL;


	tokens = malloc(buffer * sizeof(char *));
	if (tokens == NULL)
	{
		fprintf(stderr, "memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(input, DELIM_I);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;


		if (position >= buffer)
		{
			newBuffer = BUFSIZE * 2;
			backup_tokens = tokens;
			tokens = _realloc(tokens, buffer, newBuffer * sizeof(char *));
			if (tokens == NULL)
			{
				free(backup_tokens);
				free(tokens);
				exit(EXIT_FAILURE);
				free(backup_tokens);
			}
		}

		token = strtok(NULL, DELIM_I);
	}
	tokens[position] = NULL;
	return (tokens);
}



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
