#include "shell.h"

/**
 * _strlen - find the length of a string
 *
 * @s: input string
 *
 * Return: length of string s
 */

unsigned int _strlen(char *s)
{
	unsigned int len;

	if (!s)
		return (0); /* need to look up error code */
	len = 0;
	while (s[len])
		len++;
	return (len);
}
