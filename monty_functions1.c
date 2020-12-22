#include "monty.h"

/**
 * push - pushes a node on a list
 * @head: pointer to the stack head
 * @data: int to add to the node
 * @line_number: current line number
 * Return: void
 */
void push(stack_t **head, char *data, unsigned int line_number)
{
	if ((atoi(data) == 0) && (data[0] != '0'))
	{
		free_all();
		fprintf(stderr, "L%u: usage: push integer\n", line_number + 1);
		exit(EXIT_FAILURE);
	}
	add_first(head, atoi(data));
}

/**
 * pall - prints all elements of the stack
 * @head: pointer to the stack head
 * @line_number: current line number
 * Return: void
 */
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *start = *head;
	(void)line_number;

	while (start != NULL)
	{
		printf("%d\n", start->n);
		start = start->next;
	}
}

/**
 * pint - prints the top element of the stack
 * @head: pointer to the stack head
 * @line_number: current line number
 * Return: void
 */
void pint(stack_t **head, unsigned int line_number)
{
	stack_t *start = *head;

	if (start == NULL)
	{
		free_all();
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", start->n);
}

/**
 * pop - removes the top element of the stack
 * @head: pointer to the stack head
 * @line_number: current line number
 * Return: void
 */
void pop(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		free_all();
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	remove_first(head);
}

/**
 * swap - swaps the top two elements of the stack
 * @head: pointer to the stack head
 * @line_number: current line number
 * Return: void
 */
void swap(stack_t **head, unsigned int line_number)
{
	stack_t *start = *head;
	int temp;

	if (start == NULL)
	{
		free_all();
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = start->n;
	start->n = start->next->n;
	start->next->n = temp;
}
