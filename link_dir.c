#include "shell.h"

/**
 * link_dir - build a linked list of the PATH directories
 *
 * Description:
 * 1) function calls _getenv() which calls _strdup() which invokes malloc()
 * 2) function calls add_nodedir_end() which calls malloc()
 * 3) program need to call free() to release heap memory
 *
 * Return: a pointer to the head of the linked list
 */

dir_t **link_dir(dir_t **head, char *envp[])
{
	char *dirs;
	char *dir;

	dirs = _getenv("PATH", envp);
	dir = strtok(dirs, ":");

	while (dir)
	{
		add_nodedir_end(head, dir);
		dir = strtok(NULL, ":");
	}
	return (head);
}
