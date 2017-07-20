#include "shell.h"
/**
 * free_all - free all malloced memory blocks, except for double pointers
 *
 * @mem: pointer to the struct containing malloced variables
 *
 * Return: Void
 */

void free_all(mem_t *mem)
{
	dir_t *temp;
	unsigned int i;

	free(mem->s);
	mem->s = NULL; /* reset the pointer to prevent future accidental use */
	free(mem->strcp);
	mem->strcp = NULL;
	free(mem->env_cpy);
	mem->env_cpy = NULL;
	free(mem->buf);
	mem->buf = NULL;

	while (mem->h) /* free the singly linked list */
	{
		temp = mem->h;
		mem->h = mem->h->next;
		free(temp);
	}
	mem->h = NULL;

	i = 0;
	while (mem->argv[i]) /* free the argv list */
	{
		free(mem->argv[i]);
		i++;
	}
	free(mem->argv);
	mem->argv = NULL;
}
