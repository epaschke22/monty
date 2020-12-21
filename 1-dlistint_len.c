#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * dlistint_len - counts the number of nodes in a linked list
 * Return: number of nodes
 * @h: head of linked list
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t numNodes = 0;

	while (h != NULL)
	{
		numNodes++;
		h = h->next;
	}
	return (numNodes);
}
