#include "monty.h"

/**
 * push - pushes a node on a list
 * Return: void
 * @stack: 
 * @data: data to be added to new node
 */ 

void push(stack_t **stack, int data)
{
	add_first(stack, data);
}

void pall(stack_t **head, unsigned int line_number)
{
	stack_t *start = *head;

	while (start != NULL)
	{
		printf("%d\n", start->n);
		start = start->next;
	}
}
