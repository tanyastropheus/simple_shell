#include <unistd.h>
/**
 * main - print all commandline arguments, without using ac
 *
 * @argc: number of commandline arguments
 * @argv: list of commandline arguments
 *
 * Return: 0 if successful
 */

int main(int argc, char **argv)
{
	unsigned int i, j;

	(void) (argc);
	i = 0;
	while (argv[i])
	{
		j = 0;
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
