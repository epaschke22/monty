#include "monty.h"

int main(int ac, char **av)
{
	char *error = check_error(ac, av), *buffer = NULL;;
	FILE *code;
	int bytes;
	if (error != NULL)
	{
		write(STDERR_FILENO, error, strlen(error));
		free(error);
		return (EXIT_FAILURE);
	}
	code = fopen(av[1], "r");
	bytes = count_bytes(code);
	printf("%d\n", bytes);
	return (0);
}
