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
char **tokenizer(char *lineptr)
{
	char *lineptr_cp = NULL;
	const char *delim = " \t\n";
	char *token;
	int num_tokens = 0, i = 0;
	char **av = NULL;

	/*lineptr_cp = malloc(sizeof(char) * num_leido);
	if (lineptr_cp == NULL)
	{
		perror("tsh: memory allocation error");
		return (NULL);
	}
	_strcpy(lineptr_cp, lineptr);*/
	lineptr_cp = strdup(lineptr);
	token = strtok(lineptr_cp, delim);
	while (token)
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
