#include "shell.h"
/**
 * search_PATH - look for files in the current PATH
 *
 * @file: file to be found in PATH directory
 * @envp: array of pointers to environment variables
 *
 * Description: called malloc(). Need to free()
 *
 * Return: 0 if file is found,  -1 if not found
 */

/*
 * Algorithm:
 * 1) loop through linked directory list
 * 2) append the command to the directory
 * 3) check if the file exists
 */

int search_PATH(char *file, char *envp[])
{
	dir_t *head, *temp;
	dir_t **h;
	struct stat st;
	char *buf;
	unsigned int n, size;

	head = NULL;
	h = link_dir(&head, envp);
	temp = *h;
	n = 256;
	buf = malloc(sizeof(char) * n);

	while (temp)
	{
		/* need to account for '\0' and "/" */
		size = _strlen(temp->dir) + _strlen(file) + 2;
		/* if the string exceeds allocated buffer size */
		if (size > n)
		{
			free(buf);
			buf = malloc(sizeof(char) * size);
			n = size; /* expand buffer for subsequent searches */
		}
		_strcpy(buf, temp->dir);  /* copy directory to buffer */
		_strcat(buf, "/"); /* appends the command */
		_strcat(buf, file);

		if (stat(buf, &st) == 0) /* check if file exists */
		{
			write(STDOUT_FILENO, buf, _strlen(buf));
			write(STDOUT_FILENO, "\n", 1);
			return (0); /* file found */
		}
		temp = temp->next;
	}
	return (-1); /* file not found */
}
