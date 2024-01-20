#include "shell.h"
/**
 * shell - function that builds the shell
 * @void: ..
 * Return: void
 */
void shell(void)
{
	while (1)
	{
		write(1, "($): ", 5);
		char *command = NULL;
		size_t n = 0;
		int num_read = 0;

		num_read = getline(&command, &n, stdin);
		if (num_read == -1)
		{
			free(command);
			exit(-1);
		}
		if (strngcmp(command, "^C\n") == 0)
		{
			free(command);
			break;
		}
		char **argv = tokenize(command, " \n\t");
		char *path = concatenateArguments(argv);
		char **argv1 = tokenize(path, " \n\t");

		pid_t child_pid = fork();
		int status;

		if (child_pid == -1)
		{
			perror("Error");
			exit(-1);
		}
		if (child_pid == 0)
		{
			if (execve(argv1[0], argv1, NULL) == -1)
			exit(-1);
		} else
		{
			wait(&status);
		}
		freeMem(argv, path, argv1, command);
	}
}
