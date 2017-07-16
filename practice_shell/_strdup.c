#include "shell.h"

/**
 * _strdup - return a pointer to a copy of the string, stored in
 *  a newly allocated heap memory
 *
 * @str: string to be copied
 *
 * Description: program need to call free() to free heap
 *
 * Return: a pointer to a new string which is a duplicate of the string str
 */

char *_strdup(char *str)
{
	char *p;
	unsigned int i, len;

	if (!str)
	{
		return (NULL);
	}

	len = _strlen(str);
	p = malloc((len + 1) * sizeof(char));

	for (i = 0; i < len; i++)
	{
		p[i] = str[i];
	}
	p[i] = '\0';
	return (p);
}
