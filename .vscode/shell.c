#include "main.h"

/**
 * main - main loop of shell
 * Return: 0 on successs
 */

int main(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	char *token;
	int status;
	pid_t child_pid;

	while (TRUE)
	{
		_puts(PROMPT);

		if (getline(&line, &bufsize, stdin) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}


		token = strtok(line, " \t\n");
		while (token != NULL)
		{

			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
			if (child_pid == 0)
			{

				status = execvp(token, &token);
				if (status == -1)
				{
					perror("Error");
					exit(EXIT_FAILURE);
				}
			}
			else
			{

				waitpid(child_pid, &status, 0);
			}


			token = strtok(NULL, " \t\n");
		}
	}


	free(line);

	return 0;
}
