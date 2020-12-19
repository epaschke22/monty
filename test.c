#include "monty.h"

int main(int ac, char **av)
{
	char *error = check_error(ac, av);

	if (error != NULL)
	{
		write(STDERR_FILENO, error, strlen(error));
		free(error);
		return (EXIT_FAILURE);
	}
}
