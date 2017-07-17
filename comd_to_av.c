#include "shell.h"

/**
 * comd_to_av - split string s based on the delimiter specified
 *
 * @s: commandline string
 *
 * Description:
 * 1) string is modified (with delimiter replaced by '\0') after strtok()
 * 2) program need to call free() since strdup() calls malloc()
 *
 * Return: array to each word of string s
 */


/*
 * Algorithm:
 * 1) call strdup() to make a copy of the string
 * 2) loop with strtok() to find the number of tokens (note this tokenizes
 * the string by replacing the delimiter with '\0')
 * 3) call malloc() to allocate memory for an array of pointers to tokens
 * 4) loop with strtok() again on the string copy to store pointers to memory
 */

char **comd_to_av(char *s)
{
	char *word, *strcp, *tok;
	char **av;
	unsigned int w_count, i;

	strcp = _strdup(s);
	if (!strcp)
		return (NULL); /* errno set inside _strdup() */

	w_count = 0;
	word = strtok(s, "\n\t\r "); /* account for space generating keys
				      * set errno
				      */

	/* find the number of words to separate from commandline string */
	/* there is zero token if input is only a delimiter */
	while (word != NULL)
	{
		w_count++;
		word = strtok(NULL, "\n\t\r ");
	}
	av = malloc(sizeof(char *) * (w_count + 1)); /* need to add NULL ptr */

	if (!av)
		return (NULL); /* set errno */

	/* store pointers to the array allocated */
	i = 0;
	tok = strtok(strcp, "\n\t\r ");
	while (tok != NULL)
	{
		av[i] = tok;
		tok = strtok(NULL, "\n\t\r ");
		i++;
	}
	av[i] = NULL;
	return (av);
}
