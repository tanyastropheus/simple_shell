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
	char *ret;

	(void)(ac);
	(void)(av);
	while (1)
	{
		s = prompt_readline(); /* display prompt & read commandlind input */
		argv = comd_to_av(s); /* parse commandline input into argv */
		if (*argv != NULL) /* assume user did enter input */
		{
			if (argv[0][0] == '/')
			{
				if (fork_exec(argv[0], argv, envp) == -1)
				{
					errno = ECHILD;
					perror("fork");
				}
			}
			else
			{
				ret = search_PATH(argv[0], envp);
				/* command file not found */
				if (ret == NULL)
				{
					/* note: need to include command name */
					perror("not found");
				}
				else
				{
					if (fork_exec(ret, argv, envp) == -1)
					{
						errno = ECHILD;
						perror("fork");
					}
 				}
			}
		}
	}
	return (0);
}
