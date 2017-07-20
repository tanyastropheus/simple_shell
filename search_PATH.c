#include "shell.h"
/**
 * search_PATH - look for files in the current PATH
 *
 * @file: file to be found in PATH directory
 * @envp: array of pointers to environment variables
 * @mem: pointer to the mem_t struct that contains variables to be freed
 *
 * Description: called malloc(). Need to free()
 *
 * Return: pointer to the absolute path of the file, or NULL if not found
 */

/*
 * Algorithm:
 * 1) loop through linked directory list
 * 2) append the command to the directory
 * 3) check if the file exists
 */

char *search_PATH(char *file, char *envp[], mem_t *mem)
{
	dir_t *head, *temp;
	struct stat st;
	unsigned int size;

	head = NULL;
	link_dir(&head, envp, mem);
	mem->h = head; /* mem->h points to what head points to, which is
			* a node allocated on heap
			*/
	temp = head;

	while (temp)
	{
		/* need to account for '\0' and "/" */
		size = _strlen(temp->dir) + _strlen(file) + 2;
		/* allocate memory accordingly */
		mem->buf = malloc(sizeof(char) * size);
		_strcpy(mem->buf, temp->dir);  /* copy directory to buffer */
		_strcat(mem->buf, "/"); /* appends the command */
		_strcat(mem->buf, file);

		if (stat(mem->buf, &st) == 0) /* check if file exists */
			return (mem->buf); /* file found */

		temp = temp->next;
	}
	return (NULL); /* file not found */
}
