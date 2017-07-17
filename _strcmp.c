#include "shell.h"
/**
 * _strcmp - compare two strings
 *
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 0 if the strings are identical, or the difference between
 * the ASCII values of the first differing character
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (*(s1 + i) == *(s2 + i) && *(s1 + i) != '\0')
	{
		i++;
	}

	return (*(s1 + i) - *(s2 + i));
}
