#include "shell.h"

/**
 * traverse_end - traverse to the last node
 *
 * @h: head to the first node
 *
 * Return: address of the last node, or NULL if the list is uninitialized
 */

dir_t *traverse_end(dir_t *h)
{
	dir_t *temp;

	if (!h)
		return (NULL);

	temp = h;

	while (temp->next)
		temp = temp->next;

	return (temp);
}
