#include "monty.h"

/**
 * str_to_double - takes a string and outputs a double pointe
 * @input: input string to split up
 * @delm: delimiter to seperate the input
 * Return: double pointer
 */
char **str_to_double(char *input, char *delm)
{
	char **output, *item;
	unsigned int cmdlen = 0, i = 0;

	for (i = 0; input[i]; i++)
		if (input[i] == delm[0])
			cmdlen++;
	output = malloc(sizeof(char *) * (cmdlen + 2));
	if (output == NULL)
		return (NULL);
	item = strtok(input, delm);
	for (i = 0; item != NULL; i++)
	{
		output[i] = malloc(sizeof(char) * (strlen(item) + 1));
		if (output[i] == NULL)
		{
			free_double(output);
			return (NULL);
		}
		strcpy(output[i], item);
		item = strtok(NULL, delm);
	}
	output[i] = NULL;
	return (output);
}

/**
 * free_double - frees up all allocated space of a double pointer
 * @dptr: double pointer to free.
 * Return: void
 */
void free_double(char **dptr)
{
	unsigned int i = 0;

	if (dptr == NULL)
		return;
	while (dptr[i])
		free(dptr[i]), i++;
	if (dptr[i] == NULL)
		free(dptr[i]);
	free(dptr);
}
