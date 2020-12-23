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
		{"rotl", rotl}, {"rotr", rotr}, /*{"stack", stack}, {"queue" queue},*/
		{NULL, function_not_found}
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
 * Return: void
 */
void run_commands(unsigned int line_count)
{
	void (*output)(stack_t **stack, unsigned int line_number);

	if (strcmp(buckit->ops[0], "nop") == 0)
	{
		free_double(buckit->ops);
		return;
	}
	if (strcmp(buckit->ops[0], "push") == 0)
	{
		push(&(buckit->head), buckit->ops[1], line_count);
		free_double(buckit->ops);
		return;
	}
	output = get_command(buckit->ops[0]);
	if (output == NULL)
		printf("OUTPUT IS NULL");
	output(&(buckit->head), line_count);
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
		char *error = check_error(ac, av);
		FILE *code = NULL;
		unsigned int line_count = 0, i = 0;

		if (error != NULL)
		{
			write(STDERR_FILENO, error, strlen(error));
			free(error);
			return (EXIT_FAILURE);
		}
		code = fopen(av[1], "r");
		buckit = malloc(sizeof(bucket));
		if (buckit == NULL)
			return (EXIT_FAILURE);
		buckit->ops = NULL;
		buckit->head = NULL;
		while (fgets(buckit->buffer, 1024, code) != 0)
		{
			line_count++;
			if (strlen(buckit->buffer) == 1)
				continue;
			for (; buckit->buffer[i]; i++)
			{
				if (buckit->buffer[i] == '\n')
					buckit->buffer[i] = '\0';
			}
			buckit->ops = str_to_double(buckit->buffer, " ");
			run_commands(line_count);	
		}
		free_list(buckit->head);
		free(buckit);
		fclose(code);
		return (0);
	}
