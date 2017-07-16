#include "shell.h"

/**
 * _getenv - find the value of the specified environment variable
 *
 * @name: name of the environment variable
 *
 * Description:
 * 1) function calls _strdup() which invokes malloc()
 * 2) program need to call free() to free heap
 *
 * Return: pointer to the corresponding value of the environment variable
 */

/**
 * Algorithm:
 * 1) call _strdup() to copy environment list
 * 2) call strtol() to separate name and value on the env copy
 * 3) call _strcmp() to check if env_name matches given name
 * 4) return pointer to the value if the names match
 */

char *_getenv(const char *name)
{
	unsigned int i;
	char *value, *env_cpy, *env_name;

	i = 0;
	while (environ[i])
	{
		env_cpy = _strdup(environ[i]);
		if (!env_cpy)
			perror("Error");
		env_name = strtok(env_cpy, "=");

		if (_strcmp((char *)name, (char *)env_name) == 0)
		{
			value = strtok(NULL, "=");
			return (value);
		}

		i++;
	}
		return (NULL);
}
