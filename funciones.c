#include "main.h"

/**
 * *_strcpy - copies a string from a pointer to a buffer
 * @dest: buffer
 * @src:  string
 *
 * Return: void
 */
char *_strcpy(char *dest, char *src)
{
	int size;
	int i;

	size = 0;
	while (*(src + size) != '\0')
		size++;
	for (i = 0; i <= size; i++)
		*(dest + i) = src[i];
	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: int
 */
int _strcmp(char *s1, char *s2)
{
	int i, size1, size2, r;

	size1 = 0;
	size2 = 0;

	for (i = 0; s1[i] != '\0'; i++)
		size1++;
	for (i = 0; s2[i] != '\0'; i++)
		size2++;
	for (i = 0; s1[i] == s2[i]; i++)
	{
		if (i >= size1 || i >= size2)
			break;
	}
	if ((s1[i] > s2[i]) || (s1[i] < s2[i]))
		r = (s1[i] - s2[i]);
	else
		r = 0;
	return (r);
}

/**
 * _strdup - copies a string into a newly allocated space o memory
 *
 * @str: pointer to string
 *
 * Return: pointer to newly allocated space in memory
 */
char *_strdup(char *str)
{
	char *puntero;
	int i;
	int str_size;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
	}
	str_size = i;
	puntero = (char *)malloc((str_size + 1) * sizeof(char));
	if (puntero == NULL)
		return (NULL);
	for (i = 0; i <= str_size; i++)
		*(puntero + i) = *(str + i);
	return (puntero);
}

/**
 * *_strcat - appends an string to another string
 * @dest: original string
 * @src: string to be appended
 *
 * Return: char
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int n = 0;

	while (*(dest + i) != '\0')
		i++;
	while (*(src + n) != '\0')
	{
		dest[i + n] = src[n];
		n++;
	}
	return (dest);
}

/**
 * _strlen - returns the length of a string
 * @s: string
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int i = *s;
	int count = 0;

	while (i != 0)
	{
		i = *s++;
		count++;
	}
	if (count > 0)
		return (count - 1);
	else
		return (count);
}
