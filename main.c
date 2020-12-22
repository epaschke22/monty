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
		{"swap", swap}, {"add", m_add}, {"div", m_div},
		{"mul", m_mul}, {"mod", m_mod}, {"pchar", pchar}, {"pstr", pstr},
		{"rotl", rotl}, {"rotr", rotr}, /*{"stack", stack}, {"queue" queue},*/
		{NULL, NULL}
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
void run_commands(void)
{
	unsigned int i;
	void (*output)(stack_t **stack, unsigned int line_number);

	for (i = 0; buckit->lines[i] != NULL; i++)
	{
		buckit->ops = str_to_double(buckit->lines[i], " ");
		if (buckit->ops == NULL)
		{
			free_double(buckit->lines);
			free(buckit);
			exit(EXIT_FAILURE);
		}
		if (strcmp(buckit->ops[0], "nop") == 0)
		{
			free_double(buckit->ops);
			continue;
		}
		if (strcmp(buckit->ops[0], "push") == 0)
		{
			push(&(buckit->head), buckit->ops[1], i);
			free_double(buckit->ops);
			continue;
		}
		output = get_command(buckit->ops[0]);
		if (output == NULL)
			printf("OUTPUT IS NULL");
		output(&(buckit->head), i);
		free_double(buckit->ops);
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
	char *error = check_error(ac, av), *buffer = NULL;
	int bytes = 0, fd = 0;
	FILE *code = NULL;

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
	buckit = malloc(sizeof(bucket));
	if (buckit == NULL)
		return (EXIT_FAILURE);
	buckit->lines = NULL;
	buckit->ops = NULL;
	buckit->head = NULL;
	read(fd, buffer, bytes);
	close(fd);
	buckit->lines = str_to_double(buffer, "\n");
	free(buffer);
	run_commands();
	free_double(buckit->lines);
	free_list(buckit->head);
	free(buckit);
	return (0);
}
