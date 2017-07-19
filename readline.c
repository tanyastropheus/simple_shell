#include "shell.h"
/**
 * readline - read commandline input string w/o displaying prompt
 *
 * Description:
 * 1) getline() calls malloc() to allocate memory for the line
 * 2) program need to call free() after invoking this function
 *
 * Return: double pointer to the buffer where commandline string is stored
 */

char *readline(void)
{
	ssize_t r_count;
	size_t size;
	char *buf;

	buf = NULL; /* getline()  mallocs memory with appropriate size
		     * when buf == NULL
		     */

	r_count = getline(&buf, &size, stdin);

	if (r_count == -1 && buf != NULL)  /* EOF */
	{
/*		write(STDOUT_FILENO, "\n", 1);
 */		exit(0); /* need to print error msg? */
	}

	else if (r_count == -1 && buf == NULL) /* getline failed */
	{
		perror("getline");
		return (NULL);
	}
	return (buf);

}
