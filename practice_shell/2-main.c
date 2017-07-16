#include "shell.h"
/**
 * main - print out commandline arguments to stdout as a test
 * for comd_to_av function from 2-comdav.c
 *
 * @argc: number of commandline arguments
 * @argv: list of commandline arguments
 *
 * Return: 0 if successful
 */

int main(void)
{
	unsigned int i, j;
	char s[] = "This is a string";
	char **argv;

	argv = comd_to_av(s);

	i = 0;
	while (argv[i])
	{
/*		printf("first of each word: %s\n", argv[i]);
 */		j = 0;
		while (argv[i][j])
		{
			/* argv[i][j] is of char data type
			 * write() takes a pointer for its 2nd parameter
			 * hence need to pass "the address of" argv[i][j]
			 * to make it pointer type
			 */
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
