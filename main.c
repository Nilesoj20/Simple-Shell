#include "main.h"
/**
 * main - main function
 * Return: Always 0.
 */
int main(void)
{
	char *prompt = "$ ";
	char *lineptr = NULL, **av = NULL;
	ssize_t num_leido = 0;
	size_t n = 0;
	int i, run = 1;

	/*se establece la señal SIGINT para manejar el ^C */
	signal(2, _sigint);

	/* Creo un loop infinito*/
	while (run)
	{
	/* comando para saber si entro en modo interactivo*/
		if (isatty(0))
			printf("%s", prompt);
	/* leo la linea con getline*/
		num_leido = getline(&lineptr, &n, stdin);
		if (lineptr == NULL)
		{
			perror("Failed malloc: main.c, línea 24");
			exit(2);
		}
		if (num_leido == -1)
			return (0);
	/*Verifico si el input contiene solo espacios*/
		i = 0;
		while (lineptr[i] == ' ' && lineptr[i] != '\n')
			i++;
		if (lineptr[i] == '\n')
			continue;
	/*Si el input es vacío, continúa a la siguiente iteración*/
		if (_strcmp("\n", lineptr) == 0)
			continue;
		/*if (_strcmp("env\n", lineptr) == 0)
			print_env();*/
	/*Salir */
		if (_strcmp("exit\n", lineptr) == 0)
			break;
	/* tokenizar */
		av = token(num_leido, lineptr);
	/* enviamos el array con los token a ejecutar */
		ejecutar(av);
		free(av);
	}
	if (lineptr != NULL)
		free(lineptr);
	return (0);
}
