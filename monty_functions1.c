#include "monty.h"

/**
 * push - pushes a node on a list
 * @head: pointer to the stack head
 * @data: int to add to the node
 * Return: void
 */ 
void push(stack_t **head, char *data)
{
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

	temp = start->n;
	start->n = start->next->n;
	start->next->n = temp;
}
