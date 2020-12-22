#include "monty.h"

/**
 * pchar - prints first element as a character
 * @head: pointer to the stack head
 * @line_number: current line number
 * Return: void
 */
void pchar(stack_t **head, unsigned int line_number)
{
	stack_t *start = *head;

	if (start == NULL)
	{
		free_all();
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", line_number + 1);
		exit(EXIT_FAILURE);
	}
	if (start->n < 32 || start->n > 126)
	{
		free_all();
		dprintf(STDERR_FILENO, "L%u: can't pchar, value out of range\n", line_number + 1);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", start->n);
}

/**
 * pstr - prints every element as a character until end of list or out of range
 * @head: pointer to the stack head
 * @line_number: current line number
 * Return: void
 */
void pstr(stack_t **head, unsigned int line_number)
{
	stack_t *start = *head;
	(void)line_number;

	if (start == NULL)
		printf("\n");
	while (start != NULL)
	{
		if (start->n < 32 || start->n > 126)
			break;
		printf("%c", start->n);
		start = start->next;
	}
	printf("\n");
}

/**
 * rotl - puts head of stack onto the end
 * @head: pointer to the stack head
 * @line_number: current line number
 * Return: void
 */
void rotl(stack_t **head, unsigned int line_number)
{
	stack_t *start = *head;
	int temp;
	(void)line_number;

	if (start == NULL)
		return;
	temp = start->n;
	remove_first(head);
	add_end(head, temp);
}

/**
 * rotr - puts tail of stack onto the front
 * @head: pointer to the stack head
 * @line_number: current line number
 * Return: void
 */
void rotr(stack_t **head, unsigned int line_number)
{
	stack_t *start = *head;
	int temp;
	(void)line_number;

	if (start == NULL)
		return;
	while (start->next != NULL)
		start = start->next;
	temp = start->n;
	remove_end(head);
	add_first(head, temp);
}
