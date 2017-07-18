#include "shell.h"

/**
 * main - test case for the _getenv() function
 *
 * Return: 0 if successful
 */

int main(int ac, char *argv[], char *envp[])
{
	char *value;

	(void)(ac);
	(void)(argv);
	value = _getenv("PWD", envp);
	printf("%s\n", value);

	value = _getenv("PATH", envp);
	printf("%s\n", value);

	return (0);
}
