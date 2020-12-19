#include "monty.h"

char *check_error(int ac, char **av)
{
	char *message;
	char *err1 = "Error: Wrong number of arguments";
	char *err2 = "Error: file does not exist";

	if (ac != 2)
	{	
		message = err1;
		return (message);
	}
	if (fopen(av[1], "r") == NULL)
	{	
		message = err2;
		return (message);
	}	
	return (NULL);
}
