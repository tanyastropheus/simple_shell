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
	mem_t memory = {NULL, NULL, NULL, NULL, NULL, NULL};

	(void)(ac);
	(void)(av);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			memory.s = prompt_readline(&memory);
		else
			memory.s = readline(&memory);
		memory.argv = comd_to_av(memory.s, &memory);
		if (*(memory.argv) != NULL) /* assume user did enter input */
		{
			if (memory.argv[0][0] == '/') /* if command is absolute path */
			{
				if (fork_exec(memory.argv[0], memory.argv, envp) == -1)
				{
					errno = ECHILD;
					perror("fork");
				}
			}
			else
			{
				memory.buf = search_PATH(memory.argv[0], envp, &memory);
				if (memory.buf == NULL) /* if command file is not found */
					perror("not found"); /* note: need to include command name */
				else
				{
					if (fork_exec(memory.buf, memory.argv, envp) == -1)
					{
						errno = ECHILD;
						perror("fork");
					}
				}
			}
		}
		free_all(&memory);
	}
	return (0);
}
