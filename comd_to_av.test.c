#include "shell.h"
/**
 * print_argv - print out argv strings
 *
 * argv: commandline argument list
 *
 * Return: Void
 */


void print_argv(char **argv)
{
	unsigned int i;

	i = 0;
	while (argv[i])
	{
		printf("commandline argument: %s\n", argv[i]);
		i++;
	}
}

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
/*	unsigned int i, j;
 	char s1[] = "This is a string\n";
	char s2[] = "ask this\tis\n";
*/	char s3[] = "\n";
	char s4[] = "  \t\n";
	char **argv;

/*	printf("test 1:\n");
	argv = comd_to_av(s1);
	print_argv(argv);

	printf("test 2:\n");
	argv = comd_to_av(s2);
	print_argv(argv);

*/	printf("test 3:\n");
	argv = comd_to_av(s3);
	print_argv(argv);

	printf("test 4:\n");
	argv = comd_to_av(s4);
	print_argv(argv);

/*	i = 0;
	while (argv[i])
	{
		printf("first of each word: %s\n", argv[i]);
		j = 0;
		while (argv[i][j])
		{
*/			/* argv[i][j] is of char data type
			 * write() takes a pointer for its 2nd parameter
			 * hence need to pass "the address of" argv[i][j]
			 * to make it pointer type
			 */
/*			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
*/	return (0);
}
