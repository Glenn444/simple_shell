#include "shell.h"
/**
 *concatenateArguments - finds patht to argv
 * @argv: ..
 * Return: pointer to the concatenated string
 */
char *concatenateArguments(char **argv)
{
	char *path = getenv_custom("PATH");
	char *filename = argv[0];
	int totalLength = 0;
	int numArguments = 0;
	char *file_path = find_file(filename, path);
	int i;
	int spacesLength;
	char *concatenated;

	while (argv[numArguments] != NULL)
	{
		totalLength += strlength(argv[numArguments]);
		numArguments++;
	}
	spacesLength = numArguments - 1;
	concatenated = malloc(totalLength + spacesLength + 1);

	concatenated[0] = '\0';
	if (file_path)
	{
		strcat(concatenated, file_path);
		strcat(concatenated, " ");
		for (i = 1; i < numArguments; i++)
		{
			strcat(concatenated, argv[i]);

			if (i < numArguments - 1)
				strcat(concatenated, " ");
		}
	}
	else
	{
		for (i = 0; i < numArguments; i++)
		{
			strcat(concatenated, argv[i]);
			if (i < numArguments - 1)
				strcat(concatenated, " ");
		}
	}
	free(file_path);
	return (concatenated);
}
