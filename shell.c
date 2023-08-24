#include "main.h"

/**
 	* main - Main loop, receive input from CLI, parse, and execute it
 	 * @argv: Array of arguments
 	* @argc: Number of arguments passed to the program
	* Return: Always 0 on success
 */
int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	int status_return = 1, exit_status = 0; // Status variables for loop and exit status
	ssize_t n = 0;							// To check getline return value and EOF
	char **arguments = NULL;				// Array to store tokenized input arguments
	size_t size = 0;						// Size of the allocated buffer for getline
	char *input_stdin = NULL;				// Pointer to store user input

	/* Check if we continue or exit the loop */
	while (status_return && n != EOF) // EOF has a value of -1, so it is an int
	{
		size = 0; // Set buffer size to 0 for new input

		/* Return 1 if the file in the argument refers to the terminal */
		status_return = isatty(STDIN_FILENO);
		if (status_return)
			write(STDOUT_FILENO, "dav_shell->$ ", 13); // Print the prompt to stdout

		/* Store the user input string or check for EOF or any error */
		n = getline(&input_stdin, &size, stdin);
		if (n == -1) // Account for EOF or any error
		{
			free(input_stdin);
			break;
		}

		/* Check for leading/trailing spaces and skip loop iteration if found */
		if (validate_spaces(input_stdin))
		{
			free(input_stdin);
			continue;
		}

		/* Tokenize input into arguments */
		arguments = hsh_tokenizer(input_stdin);

		/* Continue loop iteration if no valid command was entered */
		if (*arguments[0] == '\0')
			continue;

		/* Execute built-in commands and update exit status */
		status_return = hsh_execute_builtins(arguments, input_stdin,
											 argv, &exit_status);

		free(arguments);   // Free allocated memory for arguments
		free(input_stdin); // Free allocated memory for input

	}

	return (0);
}
