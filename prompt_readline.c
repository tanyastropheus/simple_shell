#include "shell.h"
/**
 * prompt_readline - display prompt and read commandline input string
 *
 * Description:
 * 1) getline() calls malloc() to allocate memory for the line
 * 2) program need to call free() after invoking this function
 *
 * Return: double pointer to the buffer where commandline string is stored
 */

char *prompt_readline(void)
{
	ssize_t w_comd, r_count;
	size_t size;
	char *buf;

	buf = NULL; /* getline()  mallocs memory with appropriate size
		     * when buf == NULL
		     */

	if (write(STDOUT_FILENO, "$ ", 2) == -1)
	{
		/* check error handling function */
		return (NULL);
	}

	r_count = getline(&buf, &size, stdin);

	if (r_count == -1 && buf != NULL)  /* EOF */
	{
		errno = EINVAL; /* check this */
		if (write(STDOUT_FILENO, "\n", 1) == -1)
			return (NULL); /* check this */
		exit(0); /* need to print error msg? */
	}
	else if (r_count == -1 && buf == NULL) /* getline failed */
	{
		errno = EINVAL;
		return (NULL);
	}
	w_comd = write(STDOUT_FILENO, buf, r_count);
	if (w_comd != r_count) /* if write() failed to read line*/
	{
		/* check error handling function */
		free(buf);
		return (NULL);
	}
	/* will call free() in main, right? */
	return (buf);

}
