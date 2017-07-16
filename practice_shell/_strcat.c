/**
 * _strcat - concatenates two strings
 *
 * @dest: string that the src string is to append to
 *
 * @src: string that appends to dest
 *
 * Return: a pointer to the resulting string dest
 */

char *_strcat(char *dest, char *src)
{
	int i, j;
	int n = 0;
	int k = 0;

	/* find the strlen of *dest
	 * strlen includes '\0' due to the order of the code
	 */
	while (*(dest + n) != '\0')
	{
		n++;
	}

	/* find the strlen of *src
	 * strlen includes '\0' due to the order of the code
	 */
	while (*(src + k) != '\0')
	{
		k++;
	}

	/*append *src to the end of *dest */
	for (i = n, j = 0; j <= k; i++, j++)
	{
		*(dest + i) = *(src + j);
	}

	return (dest);
}
