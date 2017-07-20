#include "shell.h"
/**
 * readline - read commandline input string w/o displaying prompt
 *
 * @mem: pointer to the struct that contains a char pointer s to the buffer
 *
 * Description:
 * 1) getline() calls malloc() to allocate memory for the line
 * 2) program need to call free() after invoking this function
 *
 * Return: pointer to the buffer where commandline string is stored
 */

char *readline(mem_t *mem)
{
	ssize_t r_count;
	size_t size;

	mem->s = NULL; /* getline()  mallocs memory with appropriate size
			* when buf == NULL
			*/

	r_count = getline(&(mem->s), &size, stdin);

	if (r_count == -1 && mem->s != NULL)  /* EOF */
		exit(0); /* need to print error msg? */

	else if (r_count == -1 && mem->s == NULL) /* getline failed */
	{
		perror("getline");
		return (NULL);
	}
	return (mem->s);

}
