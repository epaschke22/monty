#include "monty.h"

/**
 * get_command - returns function pointer based on input name
 * @name: name to compare for function
 * Return: function pointer
 */
void (*get_command(char *name))(stack_t **stack, unsigned int line_number)
{
	instruction_t cmd_list[] = {
		{"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", m_add}, {"sub", m_sub}, {"div", m_div},
		{"mul", m_mul}, {"mod", m_mod}, {"pchar", pchar}, {"pstr", pstr},
		{"rotl", rotl}, {"rotr", rotr}, {NULL, function_not_found}
		};
	int i;

	for (i = 0; cmd_list[i].opcode != NULL; i++)
	{
		if (strcmp(cmd_list[i].opcode, name) == 0)
			break;
	}
	return (cmd_list[i].f);
}

/**
 * run_commands - runs all commands from lines
 * @line_count: current line number
 * Return: void
 */
void run_commands(unsigned int line_count)
{
	void (*output)(stack_t **stack, unsigned int line_number);

	if (strcmp(buckit->ops[0], "nop") == 0)
		;
	else if (strcmp(buckit->ops[0], "stack") == 0)
		buckit->stackmode = 0;
	else if (strcmp(buckit->ops[0], "queue") == 0)
		buckit->stackmode = 1;
	else if (strcmp(buckit->ops[0], "push") == 0)
		push(&(buckit->head), buckit->ops[1], line_count);
	else
	{
		output = get_command(buckit->ops[0]);
		output(&(buckit->head), line_count);
	}
	free_double(buckit->ops);
}

/**
 * main - reads monty files and creates a stack from monty commands
 * @ac: argument count
 * @av: argument list
 * Return: always 0
 */
int main(int ac, char **av)
{
	char *error = check_error(ac, av), buffer[1024];
	unsigned int line_count = 0, i;

	if (error != NULL)
	{
		write(STDERR_FILENO, error, strlen(error));
		free(error);
		return (EXIT_FAILURE);
	}
	buckit = malloc(sizeof(bucket));
	if (buckit == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}
	buckit->head = NULL;
	buckit->code = fopen(av[1], "r");
	buckit->stackmode = 0;
	while (fgets(buffer, 1024, buckit->code) != NULL)
	{
		line_count++;
		if (strlen(buffer) == 1 || buffer[0] == '#')
			continue;
		for (i = 0; buffer[i]; i++)
			if (buffer[i] == '\n')
				buffer[i] = '\0';
		buckit->ops = str_to_double(buffer, " ");
		run_commands(line_count);
	}
	free_list(buckit->head);
	fclose(buckit->code);
	free(buckit);
	return (0);
}
