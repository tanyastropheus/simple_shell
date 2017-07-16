#include "shell.h"

/**
 * main - print the environment using the global variable environ
 *
 * Return: 0 on success; -1 on failure
 */

int main(void)
{
	int i, j;

	i = 0;
	while (environ[i])
	{
		j = 0;
		while (environ[i][j])
		{
			if (write(STDOUT_FILENO, &environ[i][j], 1) == -1)
			{
				errno = EIO;
				perror("write() failed");
				return (-1);
			}
			j++;
		}
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);

}
