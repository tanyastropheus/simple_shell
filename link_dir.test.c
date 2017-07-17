#include "shell.h"

/**
 * main - test case of link_dir() that builds a singly linked list of
 * directories in PATH
 *
 * Return: 0 if successful
 */

int main (int ac, char *argv[], char *envp[])
{
	dir_t *head;
	dir_t *temp;
	dir_t **h;

	(void)(ac);
	(void)(argv);
	head = NULL;
	h = link_dir(&head, envp);

	temp = *h;
	while (temp)
	{
		printf("directory: %s\n", temp->dir);
		temp = temp->next;
	}
	return (0);
}
