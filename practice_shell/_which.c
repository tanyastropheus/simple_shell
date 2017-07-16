#include "shell.h"
/**
 * main - look for files in the current PATH
 *
 * @ac: number of commandline arguments
 * @av: list of commandline arguments
 *
 * Description: called malloc(). Need to free()
 *
 * Return: 0 if successful
 */

/**
 * Algorithm:
 * 1) loop through linked directory list
 * 2) append the command to the directory
 * 3) check if the file exists
 */

int main(int ac, char **av)
{
	dir_t *head, *temp;
	dir_t **h;
	struct stat st;
	char *buf;
	unsigned int n, size;

	head = NULL;
	h = link_dir(&head);
	temp = *h;
	n = 256;
	buf = malloc(sizeof(char) * n);

	if (ac < 2)
		perror("need to type in a command");
	else
	{
		while (temp)
		{
			/* need to account for '\0' and "/" */
			size = _strlen(temp->dir) + _strlen(av[1]) + 2;
			/* if the string exceeds allocated buffer size */
			if (size > n)
			{
				free(buf);
				buf = malloc(sizeof(char) * size);
				n = size; /* expand size of the buffer for subsequent search */
			}
			_strcpy(buf, temp->dir);  /* copy directory to buffer */
			_strcat(buf, "/"); /* appends /av[1] */
			_strcat(buf, av[1]);

			if (stat(buf, &st) == 0) /* check if file exists */
			{
				write(STDOUT_FILENO, buf, _strlen(buf));
				write(STDOUT_FILENO, "\n", 1);
				break;
			}
			temp = temp->next;
		}
	}
	return (0);
}
