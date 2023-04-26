#include "main.h"
/**
 * main - main function
 * Return: Always 0.
 */
int main(void)
{
	char *prompt = "Nilesoj $ ";
	char *lineptr = NULL, **av;
	ssize_t num_leido;
	size_t n = 0;
	int run = 1;


	/* Creo un loop infinito*/
	while (run)
	{
	/* comando para saber si entro en modo interactivo*/
		if (isatty(0))
			printf("%s", prompt);
	/* leo la linea con getline*/
		num_leido = getline(&lineptr, &n, stdin);
		if (num_leido == -1)
		{
			return (0);
		}
	/*Salir */
		if (strcmp("exit\n", lineptr) == 0)
		{
			free(lineptr);
			printf("soy exit \n");
			kill(0, SIGTERM);
			break;
		}
	/* tokenizar */
		av = token(num_leido, lineptr);
	/* enviamos el array con los token a ejecutar */
		ejecutar(av);
		free(av);
	}
	return(0);
}
