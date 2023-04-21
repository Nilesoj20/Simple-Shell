#include "main.h"

/**
 * main - entry point for the Holberton Shell
 *
 * Return: Always 0
 */
int main(void)
{
	char **array = NULL;
	char *line = NULL;
	int i, words_n;
	size_t len = 0;
	ssize_t read;

	printf("$ ");
	while ((read = getline(&line, &len, stdin)) != -1)
	{
		words_n = count_words(line);
		array = _strtok(line);
		for (i = 0; i < words_n; i++)
			printf("%s\n", array[i]);
		if (execve(array[0], array, NULL) == -1)
			perror("Error:");
		printf("$ ");
		if (line)
			free(line);
	}

	return (0);
}
