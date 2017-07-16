#include "shell.h"
/**
 * main - execute "ls -l /temp" in 5 different child processes
 *
 * @void: no arguments passed
 *
 * Description: Each child is created from the same parent.
 * New child is created only after old child dies.
 *
 * Return: 0 on success
 */

int main(void)
{
	pid_t pid, child_pid,  my_pid;
	int status;
	unsigned int counter;
	char *argv[] = {"/bin/ls", "-l", "/bin", NULL};

	my_pid = getpid();
	printf("parent pid: %d\n", (int)my_pid);

	counter = 0;
	do {
		pid = fork();
		if (pid == -1)
			perror("error forking");

		else if (pid > 0)
		{
			printf("my pid is: %d\n", (int) my_pid);
			child_pid = wait(&status);
			printf("child process id returned: %d\n", (int)child_pid);
		}
		else if (pid == 0)
		{
			my_pid = getpid();
			printf("inside child process, id: %d\n", (int)my_pid);
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("error executing program");
				return;  /* so that the child process ends and
					  * does not continue executing the loop
					  * inside the child process and keep
					  * forking
					  */
			}
		}
		counter++;
	} while (counter < 6);
	return (0);
}
