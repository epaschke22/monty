#include "monty.h"

global_struct *bucket;

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
		if (strcmp(cmd_list[i].opcode, name) == 0)
			return(cmd_list[i].f);
	}
	printf("WHERE IS MY FUNCTION??");
	return (NULL);
}


char *run_commands(global_struct *bucket)
{
	int i, j, error = 0;
	void (*output)(stack_t **stack, unsigned int line_number); 
	
	for (i = 0; lines[i] != NULL; i++)
	{
		bucket->ops = str_to_double(lines[i], " ");
		if (strcmp(bucket.ops[0], "nop") == 0)
			continue;
		error = check_commands(head, ops);
		if (strcmp(ops[0], "push") == 0)
		{	
			push(head, atoi(ops[1]));
			continue;
		}	
		output = get_command(ops[0]);
		if (output== NULL)
			printf("OUTPUT IS NULL");
		output(head, i);
	}
}

int main(int ac, char **av)
{
	char *error = check_error(ac, av), *buffer = NULL;
	char **lines = NULL, **ops = NULL;
	int bytes = 0, fd = 0, i;
	FILE *code = NULL;
	
	if (error != NULL)
	{
		write(STDERR_FILENO, error, strlen(error));
		free(error);
		return (EXIT_FAILURE);
	}
	bucket = malloc(sizeof(global_struct));
	bucket->lines = NULL;
	bucket->ops = NULL;
	bucket->head = NULL;
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
	close(fd);
	bucket->lines = str_to_double(buffer, "\n")i;
	free(buffer);
	run_commands(bucket->lines, bucket->head);
	return (0);
}
