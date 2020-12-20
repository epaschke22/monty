#include "monty.h"

/**
 * add_first - adds node to beginning a list
 * @head: pointer to head of list
 * @n: element to put in new node
 * Return: adress to element
 */
stack_t *add_first(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->prev = NULL;
	new->next = *head;
	*head = new;
	if (new->next != NULL)
		new->next->prev = new;
	return (*head);
}

/**
 * add_end - adds node to end a list
 * @head: pointer to head of list
 * @n: element to put in new node
 * Return: adress to element
 */
stack_t *add_end(stack_t **head, const int n)
{
	stack_t *new, *last = *head;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	new->prev = last;
	return (new);
}

/**
 * remove_first - deletes the head node
 * @head: list to modify
 * Return: 1 on success
 */
stack_t *remove_first(stack_t **head)
{
	stack_t *newhead, *tmphead;

	tmphead = *head;
	if (tmphead == NULL)
		return (0);
	if (tmphead->next == NULL)
	{
		free(tmphead);
		*head = NULL;
		return (*head);
	}
	newhead = tmphead->next;
	newhead->prev = NULL;
	free(tmphead);
	*head = newhead;
	return (*head);
}

/**
 * remove_end - deletes the last node in list
 * @head: list to modify
 * Return: 1 if successful
 */
stack_t *remove_end(stack_t **head)
{
	stack_t *temp, *tmphead;
	int len = 0, i = 0;

	tmphead = *head;
	len = dlistint_len(tmphead);
	while (i < len - 2)
	{
		tmphead = tmphead->next;
		i++;
	}
	temp = tmphead->next;
	temp->prev = NULL;
	tmphead->next = NULL;
	free(temp);
	return (*head);
}

/**
 * free_dlistint - frees memory of each item in a list
 * @head: list to free
 * Return: void
 */
void free_list(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * dlistint_len - counts the number of nodes in a linked list
 * Return: number of nodes
 * @h: head of linked list
 */
int dlistint_len(stack_t *node)
{
	int numNodes = 0;

	while (node != NULL)
	{
		numNodes++;
		node  = node->next;
	}
	return (numNodes);
}

