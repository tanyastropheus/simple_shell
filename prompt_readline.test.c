#include "shell.h"
/**
 * main - testing prompt_readline()
 *
 * Description:
 * 1) getline() calls malloc() to allocate memory for the line
 * 2) program need to call free() after invoking this function
 *
 * Return: 0 if successful
 */

int main(void)
{
	char *s;

	s = prompt_readline();
	free(s);
	return (0);
}
