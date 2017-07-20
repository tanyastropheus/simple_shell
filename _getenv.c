#include "shell.h"

/**
 * _getenv - find the value of the specified environment variable
 *
 * @name: name of the environment variable
 * @envp: list of environment variables
 * @mem: pointer to the mem_t struct that contains variables to be freed
 *
 * Description:
 * 1) function calls _strdup() which invokes malloc()
 * 2) program need to call free() to free heap
 *
 * Return: pointer to the corresponding value of the environment variable
 */

/*
 * Algorithm:
 * 1) call _strdup() to copy environment list
 * 2) call strtok() to separate name and value on the env copy
 * 3) call _strcmp() to check if env_name matches given name
 * 4) return pointer to the value if the names match
 */

char *_getenv(const char *name, char *envp[], mem_t *mem)
{
	unsigned int i;
	char *env_value, *env_name;

	i = 0;
	while (envp[i])
	{
		mem->env_cpy = _strdup(envp[i]);
		if (!(mem->env_cpy))
		{
			errno = ENOMEM;
			return (NULL);
		}
		env_name = strtok(mem->env_cpy, "=");

		if (_strcmp((char *)name, (char *)env_name) == 0)
		{
			env_value = strtok(NULL, "=");
			return (env_value);
		}
		free(mem->env_cpy);
		mem->env_cpy = NULL;
		i++;
	}
		return (NULL);
}
