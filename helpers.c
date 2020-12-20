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
	char *err1 = "USAGE: monty file\n", *err2 = "Error: Can't open file ";
		
	if (ac != 2)
	{
		message = malloc((strlen(err1) + 1) * sizeof(char));
		strcpy(message, err1);
		return (message);
	}
	if (fopen(av[1], "r") == NULL)
	{
		message = malloc((strlen(err2) + strlen(av[1]) + 2) * sizeof(char));
		strcpy(message, err2);
		strcat(message, av[1]);
		strcat(message, "\n\0");
		return (message);
	}
	return (NULL);
}

/**
 * count_bytes - counts the number of bytes in a file
 * Return: number of bytes
 * @file: file pointer to file that will have bytes counted
 */

int count_bytes(FILE *file)
{
	int bytes;

	for (bytes = 0; getc(file) != EOF; bytes++)
		;
	return (bytes);
}
