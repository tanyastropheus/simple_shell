#include "shell.h"

/**
 * main - test case for the _getenv() function
 *
 * Return: 0 if successful
 */

int main(void)
{
	char *value;

	value = _getenv("PWD");
	printf("%s\n", value);

	value = _getenv("PATH");
	printf("%s\n", value);

	return (0);
}
