#include "shell.h"

/**
 * fork_exec - fork and execute program in the child process
 *
 * @file: pointer to the string that is the command to be executed
 * @argv: list of pointers to commandline arguments
 * @envp: list of pointers to environment variables
 *
 * Description:
 * also checks if the command is executable by execve it
 *
 * Return: 0 if successful, -1 if failed
 */

int fork_exec(char *file, char *argv[], char *envp[])
{
	pid_t pid;
	int status;
	int ret;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	else if (pid > 0)
	{
		wait(&status);
		return (0);
	}
	else if (pid == 0)
	{
		ret = execve(file, argv, envp);
		if (ret == -1)  /* program not executable */
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
