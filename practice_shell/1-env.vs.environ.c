#include "shell.h"

/**
 * main - print the addresses of env and environ
 *
 * @ac: number of commandline arguments
 * @av: list of commandline arguments
 * @env: list of environment variables
 *
 * Return: 0 on success; -1 on failure
 */

int main(int ac, char **av, char **env)
{
	(void)(ac);
	(void)(av);

	printf("address of env: %p\n", (void *) env);
	printf("address of environ: %p\n", (void *) environ);

	return (0);
}
