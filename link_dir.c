#include "shell.h"

/**
 * link_dir - build a linked list of the PATH directories
 *
 * @head: double pointer to the head that points to the singly linked list
 * @envp: list of environment variables
 * @mem: pointer to the mem_t struct that contains variables to be freed
 *
 * Description:
 * 1) function calls _getenv() which calls _strdup() which invokes malloc()
 * 2) function calls add_nodedir_end() which calls malloc()
 * 3) program need to call free() to release heap memory
 *
 * Return: a pointer to the head of the linked list
 */

dir_t **link_dir(dir_t **head, char *envp[], mem_t *mem)
{
	char *dirs;
	char *dir;

	dirs = _getenv("PATH", envp, mem);
	dir = strtok(dirs, ":");

	while (dir)
	{
		add_nodedir_end(head, dir);
		dir = strtok(NULL, ":");
	}
	return (head);
}
