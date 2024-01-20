#include "shell.h"
/**
 *getenv_custom - implements get_env func
 *@name: ..
 * Return: pointer to environment
 */
char *getenv_custom(const char *name)
{
	char **env;
	size_t name_len;
	
	name_len = strlength(name);
	for (env = environ; *env != NULL; ++env)
	{
		if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
			return (&((*env)[name_len + 1]));
	}
	return (NULL);
}
