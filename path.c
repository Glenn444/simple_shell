#include "shell.h"
/**
 *getenv_custom - implements get_env func
 *@name: ..
 * Return: pointer to environment
 */
char *getenv_custom(const char *name)
{
	size_t name_len = strlength(name);

	for (char **env = environ; *env != NULL; ++env)
	{
		if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
			return (&((*env)[name_len + 1]));
	}
	return (NULL);
}
/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
    unsigned int i;

    i = 0;
    while (env[i] != NULL)
    {
        printf("%s\n", env[i]);
        i++;
    }
    return (0);
}
