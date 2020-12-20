#include "monty.h"

void run_commands(char **lines)
{
	stack_t **head;
	int i, j;
	char **ops = NULL;
	char *cmd_list[] = {
		"push", "pall", "pint", "pop", "swap", "add", "nop", "div",
		"mul", "mod", "pchar", "pstr", "rotl", "rotr", "stack", "queue"
		};

	for (i = 0; lines[i] != NULL; i++)
	{
		ops = str_to_double(lines[i], " ");
		for (j = 0; cmd_list[j]; j++)
			print("line");
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
	run_commands(lines);
	free_double(lines);
	close(fd);
	return (0);
}
