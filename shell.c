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
		char *command;
		size_t n;
		int num_read;
		char **argv;
		char *path;
		char **argv1;
		pid_t child_pid;
		int status;

		write(1, "($): ", 5);
		command = NULL;
		n = 0;
		num_read = 0;
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
		argv = tokenize(command, " \n\t");
		path = concatenateArguments(argv);
		argv1 = tokenize(path, " \n\t");

		child_pid = fork();
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
