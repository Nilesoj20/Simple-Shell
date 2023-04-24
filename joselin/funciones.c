#include "main.h"

/**
 * _strncpy - copia n bytes de una cadena en otra
 * @dest: cadena destino
 * @src: cadena fuente
 * @n: número de bytes a copiar
 * Return: la cadena destino
 */
char *_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}

/**
 * _strlen - longitud de una cadena
 * @s: cadena
 * Return: longitud de la cadena
 */
size_t _strlen(const char *s)
{
	size_t len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}
