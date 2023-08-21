#include "shell.h"

/**
 * main - main loop of shell
 * Return: 0 on success
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

		// use getline to see the entrance
		if (getline(&line, &bufsize, stdin) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}

		// new line with stork
		token = strtok(line, " \t\n");
		while (token != NULL)
		{
			// new child processus
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
			if (child_pid == 0)
			{
				// excute command in child processus
				status = execvp(token, &token);
				if (status == -1)
				{
					perror("Error");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				// wait child processus
				waitpid(child_pid, &status, 0);
			}

			// get next token
			token = strtok(NULL, " \t\n");
		}
	}

	//anti memory leak
	free(line);

	return 0;
}
