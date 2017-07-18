#include "shell.h"
/**
 * main - a simple commandline interpreter
 *
 * @ac: number of commandlind arguments
 * @av: array of pointers to commandline arguments
 * @envp: array of pointers to environment variables
 *
 * Return: 0 on success, or -1 on failure
 */

int main(int ac, char *av[], char *envp[])
{
	char *s;
	char **argv;
	int ret_1, ret_2;

	(void)(ac);
	(void)(av);
	while (1)
	{
		s = prompt_readline();
		argv = comd_to_av(s);
		if (*argv != NULL)
		{
			ret_1 = search_PATH(argv[0], envp);
			if (ret_1 == -1) /* command file not found */
			{
				/* note: need to include command name */
				perror("not found");
			}
			else
			{
				ret_2 = fork_exec(argv, envp);
				if (ret_2 == -1)
				{
					errno = ECHILD;
					perror("fork");
				}
			}
		}
	}
	return (0);
}
