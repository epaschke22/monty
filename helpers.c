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
	FILE *file = NULL;	
	
	if (ac != 2)
	{
		message = malloc((strlen(err1) + 1) * sizeof(char));
		if (message == NULL)
		{	
			printf("Memory Error");
			return (NULL);
		}
		strcpy(message, err1);
		return (message);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		message = malloc((strlen(err2) + strlen(av[1]) + 2) * sizeof(char));
		if (message == NULL)
		{
			printf("Memory Error");
			return (NULL);
		}	
		strcpy(message, err2);
		strcat(message, av[1]);
		strcat(message, "\n\0");
		return (message);
	}
	else
		fclose(file);
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


/**
 * list_len- counts the number of nodes in a linked list
 * Return: number of nodes
 * @h: head of linked list
 */
int list_len(stack_t *h)
{
	int numNodes = 0;

	while (h != NULL)
	{
		numNodes++;
		h = h->next;
	}
	return (numNodes);
}
