#include "shell.h"
/**
 *
 */
void freeMem(char **arg1, char *arg2, char **arg3, char *command)
{
	int i = 0;

	while (arg1[i] != NULL)
		i++;
	for (int j = 0; j < i; j++)
	{
		free(arg1[j]);
		free(arg3[j]);
	}
	free(arg1);
	free(arg2);
	free(arg3);
	free(command);
}
