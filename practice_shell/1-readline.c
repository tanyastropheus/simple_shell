#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
/**
 * main - display prompt, read command line input, and write input to stdout
 *
 * Description:
 * 1) getline() calls malloc() to allocate memory for the line
 * 2) program need to call free() after invoking this function
 *
 * Return: 0 if successful
 */

int main(void)
{
	ssize_t w_comd, r_count;
	size_t size;
	char *buf;

	buf = NULL; /* getline()  mallocs memory with appropriate size
		     * when buf == NULL
		     */

	if (write(STDOUT_FILENO, "$ ", 2) == -1)
	{
		errno = EIO;
		perror("write() cannot display prompt");
		return (-1);
	}

	r_count = getline(&buf, &size, stdin);

	if (r_count == -1)
	{
		errno = EIO;
		perror("getline() cannot read input");
		return (-1);
	}

	w_comd = write(STDOUT_FILENO, buf, r_count);
	if (w_comd != r_count)
	{
		errno = EIO;
		perror("write() cannot display input");
		free(buf);
		return (-1);
	}
	free(buf);
	return (0);
}
