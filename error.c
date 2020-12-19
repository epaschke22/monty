#include "monty.h"

/**
 * check_error - checks to see if number of arguments
 * is correct and the file to be opened exists
 * @ac: number of arguments from main
 * @av: array of arguments from main
 * Return: returns error message if error is
 * found else NULL
 */

char *check_error(int ac, char **av)
{
	char *message;
	char *err1 = "Error: Wrong number of arguments\n";
	char *err2 = "Error: file does not exist\n";

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
