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

    start->next->n = start->n % start->next->n;
    remove_first(head);
}