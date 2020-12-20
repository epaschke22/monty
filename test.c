#include "monty.h"

int main(int ac, char **av)
{
	char *error = check_error(ac, av), *buffer = NULL;
	char **lines = NULL, **ops = NULL;
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
	read(fd, buffer, bytes);
	lines = str_to_double(buffer, "\n");
	free(buffer);
	free_double(lines);
	close(fd);
	return (0);
}
