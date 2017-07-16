#include "shell.h"

/**
 * comd_to_av - split commandline string input to argv list
 *
 * @s: commandline string
 *
 * Description:
 * 1) string is modified (with delimiter replaced by '\0') after strtok()
 * 2) program need to call free() since strdup() calls malloc()
 *
 * Return: array to each word of string s
 */

/**
 * Algorithm:
 * 1) call strdup() to make a copy of the string
 * 2) loop with strtok() to find the number of tokens (note this tokenizes
 * the string by replacing the delimiter with '\0')
 * 3) call malloc() to allocate memory for an array of pointers to tokens
 * 4) loop with strtok() again on the string copy to store the pointers to memory
 */

char **comd_to_av(char *s)
{
	char *word, *strcp, *tok;
	char **av;
	unsigned int w_count, i;

	strcp = _strdup(s);

	w_count = 0;
	word = strtok(s, " ");

	/* find the number of words to separate from commandline string */
	while (word != NULL)
	{
		w_count++;
		word = strtok(NULL, " ");
	}

	av = malloc(sizeof(char *) * (w_count + 1));
	if (!av)
		return (NULL); /* need to look up appropriate error code */

	/* store pointers to the array allocated */
	i = 0;
	tok = strtok(strcp, " ");
	while (tok != NULL)
	{
		av[i] = tok;
		tok = strtok(NULL, " ");
		i++;
	}
	av[i] = NULL;
	return (av);
}
