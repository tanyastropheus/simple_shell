#include "shell.h"
/**
 * prompt_readline - display prompt and read commandline input string
 *
 * @mem: pointer to the struct that contains a char pointer s to the buffer
 *
 * Description:
 * 1) getline() calls malloc() to allocate memory for the line
 * 2) program need to call free() after invoking this function
 *
 * Return: pointer to the buffer where commandline string is stored
 */

char *prompt_readline(mem_t *mem)
{
	ssize_t r_count;
	size_t size;

	mem->s = NULL; /* getline()  mallocs memory with appropriate size
		     * when buf == NULL
		     */

	if (write(STDOUT_FILENO, "$ ", 2) == -1)
	{
		/* check error handling function */
		return (NULL);
	}

	r_count = getline(&(mem->s), &size, stdin);

	if (r_count == -1 && mem->s != NULL)  /* EOF */
	{
		write(STDOUT_FILENO, "\n", 1);
		free(mem->s);
		exit(0); /* need to print error msg? */
	}

	else if (r_count == -1 && mem->s == NULL) /* getline failed */
	{
		perror("getline");
		return (NULL);
	}
	return (mem->s);

}
