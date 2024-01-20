#include "shell.h"
/**
 *find_file - ...
 *@filename: ..
 * @path: ..
 * Return: pointer to file path
 */
char *find_file(char *filename, char *path)
{
	char *token;
	char *path_copy = strdup(path);
	char *search_path = path_copy;

	while ((token = strtok(search_path, ":")) != NULL)
	{
		char *file_path = malloc(strlen(token) + strlen(filename) + 2);

		sprintf(file_path, "%s/%s", token, filename);
		if (access(file_path, F_OK) != -1)
		{
			free(path_copy);
			return (file_path);
		}
		else
		{
			free(file_path);
			search_path = NULL;
		}
	}
	free(path_copy);
	return (NULL);
}
