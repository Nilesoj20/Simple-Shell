#include "main.h"
/**
* _strncpy - check the code
* @dest: pointer
* @src: pointer
* @n: variable
* Return: Always void.
*/
char *_strncpy(char *dest, char *src)
{
	char *cp = dest;
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	*dest = '\0';
	return (c);
}
/**
 * _strlen - string length
 * @s: string
 * Return: result
 *
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}
