#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct data - things we need for functions
 * @lines: lines from files
 * @ops: lines separated by command and args
 */
typedef struct data {
	char **lines;
	char **ops;
	stack_t *head;
} bucket;

bucket *buckit;

/*str_to_double.c*/
char **str_to_double(char *input, char *delm);
void free_double(char **dptr);

/*linkedlist_functions.c*/
stack_t *add_first(stack_t **head, const int n);
stack_t *add_end(stack_t **head, const int n);
stack_t *remove_first(stack_t **head);
stack_t *remove_end(stack_t **head);
void free_list(stack_t *head);

/*helpers.c*/
char *check_error(int ac, char **av);
int count_bytes(FILE *file);
void free_all(void);

/*monty_functions1.c*/
void push(stack_t **head, char *data);
void pall(stack_t **head, unsigned int line_number);
void pint(stack_t **head, unsigned int line_number);
void pop(stack_t **head, unsigned int line_number);
void swap(stack_t **head, unsigned int line_number);

/*monty_functions2.c*/
void m_add(stack_t **head, unsigned int line_number);
void m_sub(stack_t **head, unsigned int line_number);
void m_div(stack_t **head, unsigned int line_number);
void m_mul(stack_t **head, unsigned int line_number);
void m_mod(stack_t **head, unsigned int line_number);
#endif
