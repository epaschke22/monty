#include "monty.h"

void (*get_command(char *name))(stack_t **stack, unsigned int line_number)
{
	instruction_t cmd_list[] = {
		{"pall", pall}, /*{"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add}, {"div", div},
		{"mul", mul}, {"mod", mod}, {"pchar", pchar}, {"pstr", pstr},
		{"rotl", rotl}, {"rotr", rotr}, {"stack", stack}, {"queue" queue},*/
		{NULL, NULL}
		};
	int i;

	for (i = 0; cmd_list[i].opcode != NULL; i++)
	{
		if (cmd_list[i].opcode == *name)
			return(cmd_list[i].f)
	}
	return (NULL)
}


void run_commands(char **lines, stack_t **head)
{
	int i, j;
	void (*output)(stack_t **stack, unsigned int line_number); 
	char **ops = NULL;
	
	for (i = 0; lines[i] != NULL; i++)
	{
		ops = str_to_double(lines[i], " ");
		if (strcmp(ops[0], "nop") == 0)
			continue;
		if (strcmp(ops[0], "push") == 0)
			/* run push function here */
		output = get_command(ops[0]);
		if (output== NULL)
			print_error(ops[0], i, lines, head);
		output(&head, i);
	}
}

int main(int ac, char **av)
{
	stack_t *head;
	char *error = check_error(ac, av), *buffer = NULL;
	char **lines = NULL, **ops = NULL;
	int bytes = 0, fd = 0, i;
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
