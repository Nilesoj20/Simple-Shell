#include "main.h"
/**
 * token - splits an array into words separated
 *         b a delimiter character
 * @num_leido: size of the string
 * @lineptr: string to be splitted into words
 *
 * Return: an array of strings where each string
 *         is a different word
 */
char **token(ssize_t num_leido, char *lineptr)
{
	char *lineptr_cp = NULL;
	const char *delim = " \n";
	char *token;
	int num_tokens = 0, i = 0;
	char **av;

	lineptr_cp = malloc(sizeof(char) * (num_leido + 1));
	if (lineptr_cp == NULL)
	{
		perror("tsh: memory allocation error");
		return (NULL);
	}
	strcpy(lineptr_cp, lineptr);
	token = strtok(lineptr_cp, delim);
	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	av = malloc(sizeof(char *) * (num_tokens + 1));
	if (av == NULL)
	{
		free(lineptr_cp);
		perror("Error array av");
		return (NULL);
	}
	token = strtok(lineptr, delim);
	for (i = 0; token != NULL; i++)
	{
		av[i] = token;
		token = strtok(NULL, delim);
	}
	av[i] = NULL;
	free(lineptr_cp);
	return (av);
}
