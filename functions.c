#include "monty.h"

/**
 * push - pushes a node on a list
 * Return: void
 * @stack: 
 * @data: data to be added to new node
 */ 

void push(stack_t **stack, unsigned int line_number, char *data, char **ops, char **lines)
{
	int i;

	for (i = 0; data[i]; i++)
	{
		if (isdigit(data[i]) == 0)
		{
			free_double(lines);
			free_double(ops);
			free_list(*stack);
			printf("L%n: usage: push integer", line_number);
		}
	}
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
