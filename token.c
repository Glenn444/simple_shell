#include "shell.h"
/**
 *tokenize - implements strtok func
 * @command: ..
 * @delim: ..
 * Return: pointer to tokenized argv
 */
char **tokenize(char *command, char *delim)
{
	char **argv;
	char *cpyCommand = strngdup(command);
	char *cpyCommand2 = strngdup(command);
	int num_tokens = 0;
	char *token = strtok(cpyCommand, delim);

	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	argv = malloc((num_tokens + 1) * sizeof(char *));
	token = strtok(cpyCommand2, delim);
	int i = 0;

	while (token != NULL)
	{
		argv[i] = malloc((strlength(token) + 1) * sizeof(char));
		strngcpy(argv[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	argv[i] = NULL;
	free(token);
	free(cpyCommand);
	free(cpyCommand2);
	return (argv);
}
