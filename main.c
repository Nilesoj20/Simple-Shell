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
	
	/*macro para evitar advertencia del compilador*/
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
		if (num_leido == -1)
		{
			free(lineptr);
			return (0);
		}
	/*Si el input es vacío, continúa a la siguiente iteración*/
		if (_strcmp("\n", lineptr) == 0)
			continue;
	/*imprime built-in*/
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
