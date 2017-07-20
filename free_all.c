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

	free(mem->s);
	mem->s = NULL; /* reset the pointer to prevent future accidental use */
	free(mem->strcp);
	mem->strcp = NULL;
	/*
	 * no need to free argv[i] in a loop, since the string argv
	 * points to (mem->strcp), which is a contiguous array tokenized into
	 * argv[i]
	 */
	free(mem->argv);
	mem->argv = NULL;
	free(mem->env_cpy);
	mem->env_cpy = NULL;
	free(mem->buf);
	mem->buf = NULL;

/* free the singly linked list */
	while (mem->h)
	{
		temp = mem->h;
		mem->h = mem->h->next;
		free(temp);
	}
	mem->h = NULL;
}
