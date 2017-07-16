#include "shell.h"

/**
 * print_dir - prints each directory contained in the the environment
 * variable PATH, one directory per line.
 *
 * Description:
 * 1) function calls _getenv() which calls malloc()
 * 2) program needs to call free() to release heap
 *
 * Return: 0 if successful
 */

int print_dir(void)
{
	char *dir_s, *dir;

	dir_s = _getenv("PATH");
	dir = strtok(dir_s, ":");

	while (dir)
	{
		if (write(STDOUT_FILENO, dir, _strlen(dir)) == -1)
			perror("Error");
		if (write(STDOUT_FILENO, "\n", 1) == -1)
			perror("Error");
		dir = strtok(NULL, ":");
	}
	return (0);
}
