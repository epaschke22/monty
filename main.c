#include "monty.h"

/**
 * get_command - returns function pointer based on input name
 * @name: name to compare for function
 * @stack: linked list that poitns to head used in each function
 * @line_number: the current line number count to be used within each function
 * Return: function pointer
 */
void (*get_command(char *name))(stack_t **stack, unsigned int line_number)
{
	instruction_t cmd_list[] = {
		{"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", m_add}, {"div", m_div},
		{"mul", m_mul}, {"mod", m_mod}, /*{"pchar", pchar}, {"pstr", pstr},
		{"rotl", rotl}, {"rotr", rotr}, {"stack", stack}, {"queue" queue},*/
		{NULL, NULL}
		};
	int i;

	for (i = 0; cmd_list[i].opcode != NULL; i++)
	{
		if (strcmp(cmd_list[i].opcode, name) == 0)
			return(cmd_list[i].f);
	}
	printf("WHERE IS MY FUNCTION??");
	return (NULL);

}

/**
 * run_commands - runs all commands from lines
 * @lines: double pointer of each line from the monty file
 * @head: linked list stack pointing to head
 * Return: always 0
 */
void run_commands(char **lines, stack_t **head)
{
	unsigned int i;
	void (*output)(stack_t **stack, unsigned int line_number); 
	char **ops = NULL;
	
	for (i = 0; lines[i] != NULL; i++)
	{
		ops = str_to_double(lines[i], " ");
		if (strcmp(ops[0], "nop") == 0)
		{
			free_double(ops);
			continue;
		}
		if (strcmp(ops[0], "push") == 0)
		{
			push(head, ops[1]);
			free_double(ops);
			continue;
		}
		/*check error function that takes line and ops to be freed */
		output = get_command(ops[0]);
		if (output== NULL)
			printf("OUTPUT IS NULL");
		output(head, i);
		free_double(ops);
	}
}

/**
 * main - reads monty files and creates a stack from monty commands
 * @ac: argument count
 * @av: argument list
 * Return: always 0
 */
int main(int ac, char **av)
{
	stack_t *head = NULL;

	char *error = check_error(ac, av), *buffer = NULL;
	char **lines = NULL;
	int bytes = 0, fd = 0;
	FILE *code = NULL;

	head = NULL;
	if (error != NULL)
	{
		write(STDERR_FILENO, error, strlen(error));
		free(error);
		return (EXIT_FAILURE);
	}
	code = fopen(av[1], "r");
	bytes = count_bytes(code);
	fclose(code);
	fd = open(av[1], O_RDWR);
	if (fd == -1)
		return (EXIT_FAILURE);
	buffer = malloc(sizeof(char) * bytes);
	if (buffer == NULL)
	{
		printf("Buffer Memory Error");
		return (0);
	}    
	read(fd, buffer, bytes);
	lines = str_to_double(buffer, "\n");
	free(buffer);
	run_commands(lines, &head);
	free_double(lines);
	close(fd);
	return (0);
}
