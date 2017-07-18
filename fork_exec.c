#include "shell.h"

/**
 * fork_exec - fork and execute program in the child process
 *
 * @av: list of pointers to commandline arguments
 * @envp: list of pointers to environment variables
 *
 * Description:
 * also checks if the command is executable by execve it
 *
 * Return: 0 if successful, -1 if failed
 */

int fork_exec(char *file, char *argv[], char *envp[])
{
	pid_t pid, my_pid;
	int status;
	int ret;

	my_pid = getpid();
	printf("parent pid: %d\n", (int)my_pid);

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	else if (pid > 0)
	{
		printf("my pid is: %d\n", (int) my_pid);
/*		free();
 */		wait(&status);
		return (0);
	}
	else if (pid == 0)
	{
		my_pid = getpid();
		printf("inside child process, id: %d\n", (int)my_pid);
		printf("command to be excuted: %s\n", file);
		ret = execve(file, argv, envp);
		printf("execve return: %d\n", ret);
		if (ret == -1)  /* program not executable */
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
