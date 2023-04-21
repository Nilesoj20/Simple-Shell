#include "main.h"

/**
 * count_words - counts the number of words in a string
 * @str: string
 *
 * Return: number of words in the string
 */
int count_words(char *str)
{
	int i, counter;

	counter = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && str[i] != '\t'
				&& str[i] != '\n')
			continue;
		else
			counter++;
	}
	counter++;

	return (counter);
}

/**
 * _strtok - separates a string into an array of words
 * @str: string
 *
 * Return: an array of strings
 */
char **_strtok(char *str)
{
	char **str_array;
	int words_n, word_len, n, j, k, i = 0;

	words_n = count_words(str);
	str_array = malloc((words_n + 1) * sizeof(char *));
	if (str_array == NULL)
		exit(-1);
	for (j = 0; j < words_n; j++)
	{
		while (str[i] == ' ' || str[i] == '\t'
				|| str[i] == '\n' || str[i] == '\0')
			i++;
		n = i;
		for (word_len = 0; str[i] != '\0'; i++)
		{
			if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
				word_len++;
			else
				break;
		}
		str_array[j] = malloc((word_len + 1) * sizeof(char));
		if (str_array[j] == NULL)
		{
			for (k = j - 1; k <= 0; k--)
				free(str_array[k]);
			free(str_array);
			exit(-1);
		}
		for (k = 0; n < i; n++)
		{
			if (str[n] != ' ' && str[n] != '\t'
					&& str[n] != '\n')
				str_array[j][k++] = str[n];
			else
				break;
		}
		str_array[j][k] = '\0';
	}
	str_array[j] = NULL;
	return (str_array);
}
