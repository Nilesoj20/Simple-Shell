#include "main.h"

#define UNUSED(x) (void)(x)

/**
 * main - main function
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	char *prompt = "Nilesoj $ ";
	char *lineptr = NULL, **args = NULL;
	ssize_t num_leido = 0;
	size_t n = 0;
	int run = 1;

	UNUSED(argc);
	UNUSED(argv);
	/*se establece la señal SIGINT para manejar el ^C */
	signal(SIGINT, _sigint);

	/* Creo un loop infinito*/
	while (run)
	{
	/* comando para saber si entro en modo interactivo*/
		if (isatty(STDIN_FILENO))
			printf("%s", prompt);
	/* leo la linea con getline*/
		num_leido = getline(&lineptr, &n, stdin);
		/*if (lineptr == NULL)
		{
			perror("Failed malloc: main.c, línea 24");
			return (0);
		}*/
		if (num_leido == -1)
		{
			free(lineptr);
			return (0);
		}
	/*Verifico si el input contiene solo espacios*/
		/*i = 0;
		while (lineptr[i] == ' ' && lineptr[i] != '\n')
			i++;
		if (lineptr[i] == '\n')
			continue;*/
	/*Si el input es vacío, continúa a la siguiente iteración*/
		if (_strcmp("\n", lineptr) == 0)
			continue;
		if (_strcmp("env\n", lineptr) == 0)
		{
			print_env();
			continue;
		}
	/*Salir */
		if (strcmp("exit\n", lineptr) == 0)
			break;
	/* tokenizar */
		args = tokenizer(lineptr);
	/* enviamos el array con los token a ejecutar */
		run = ejecutar(args);
		free(args);
	}
	free(lineptr);
	return (0);
}
