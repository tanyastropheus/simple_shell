#include "shell.h"

/**
 * main - test case of the add_nodedir_end function that builds
 * a linked list of directories in PATH
 *
 * Return: 0 if successful
 */

int main (void)
{
	dir_t *head;
	dir_t *temp;
	dir_t **h;

	head = NULL;
	h = link_dir(&head);

	temp = *h;
	while (temp)
	{
		printf("directory: %s\n", temp->dir);
		temp = temp->next;
	}
	return (0);
}
