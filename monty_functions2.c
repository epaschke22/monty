#include "monty.h"

/**
 * add - adds the top two elements
 * @head: pointer to the stack head
 * @line_number: current line number
 * Return: void
 */
void m_add(stack_t **head, unsigned int line_number)
{
    stack_t *start = *head;

    if (start == NULL || start->next == NULL)
    {
		free_all();
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number + 1); 
		exit(EXIT_FAILURE);
	}

    start->next->n = start->n + start->next->n;
    remove_first(head);
}

/**
 * sub - subtracts the top two elements
 * @head: pointer to the stack head
 * @line_number: current line number
 * Return: void
 */
void m_sub(stack_t **head, unsigned int line_number)
{
    stack_t *start = *head;

    if (start == NULL || start->next == NULL)
    {
		free_all();
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number + 1); 
		exit(EXIT_FAILURE);
	}

    start->next->n = start->n - start->next->n;
    remove_first(head);
}

/**
 * add - divides the top two elements
 * @head: pointer to the stack head
 * @line_number: current line number
 * Return: void
 */
void m_div(stack_t **head, unsigned int line_number)
{
    stack_t *start = *head;

    if (start == NULL || start->next == NULL)
    {
		free_all();
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number + 1); 
		exit(EXIT_FAILURE);
	}

    start->next->n = start->n / start->next->n;
    remove_first(head);
}

/**
 * mul - multiplies the top two elements
 * @head: pointer to the stack head
 * @line_number: current line number
 * Return: void
 */
void m_mul(stack_t **head, unsigned int line_number)
{
    stack_t *start = *head;

    if (start == NULL || start->next == NULL)
    {
		free_all();
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number + 1); 
		exit(EXIT_FAILURE);
	}

    start->next->n = start->n * start->next->n;
    remove_first(head);
}

/**
 * mod - modulos the top two elements
 * @head: pointer to the stack head
 * @line_number: current line number
 * Return: void
 */
void m_mod(stack_t **head, unsigned int line_number)
{
    stack_t *start = *head;

    if (start == NULL || start->next == NULL)
    {
		free_all();
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number + 1); 
		exit(EXIT_FAILURE);
	}

    if (start->n == 0)
    {
		free_all();
		fprintf(stderr, "L%u: division by zero\n", line_number + 1); 
		exit(EXIT_FAILURE);
	}

    start->next->n = start->n % start->next->n;
    remove_first(head);
}