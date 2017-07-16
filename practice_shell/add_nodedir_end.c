#include "shell.h"

/**
 * add_nodedir_end - add a node at the end  of a dir_t list
 *
 * @head: head to the first node
 * @ptr: pointer to the directory in PATH that is to be  stored at the node
 *
 * Return: address of the last node, or NULL if failed
 */

dir_t *add_nodedir_end(dir_t **head, char *s)
{
	dir_t *end_node;
	dir_t *temp;

	end_node = malloc(sizeof(dir_t));

	if (!end_node)
		return (NULL);

	end_node->dir = s;
	end_node->next = NULL;

	if (*head == NULL) /* if the list is uninitialized */
		*head = end_node;
	else
	{
		temp = traverse_end(*head);
		temp->next = end_node;
	}
	return (end_node);
}
