/**
 * _strcpy - copy a string pointed to by src to the buffer pointed to by dest
 *
 * @dest: pointer to the buffer
 *
 * @src: pointer to the string to be copied
 *
 * Return: dest
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	/* 1 evaluates to "true", which creates an infinite loop */
	while (1)
	{
		*(dest + i) = *(src + i);
		/* need to copy the null character at the end as well */
		if (*(src + i) == '\0')
		{
			return (dest);
		}
		i++;
	}
}
