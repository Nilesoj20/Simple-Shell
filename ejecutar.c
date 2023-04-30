#include "main.h"

/**
 * ejecutar - ejecuta el comando ingresado por el usuario
 * @av: array de strings, donde cada string es una palabra del input
 *
 * Return: void
 */
int ejecutar(char **av)
{
	pid_t pid;
	int status;
	struct stat buffer;
	char *comando = NULL;

	comando = av[0];
	if (stat(comando, &buffer) != 0)
	{
		printf("Error: comando incorrecto stat, linea 18, ejecutar\n");
		return (0);
	}
	if (comando == NULL)
	{
		printf("Error: comando incorrecto\n");
		return (0);
	}
	else
	{
		/*creo un proceso hijo*/
		pid = fork();
		/* valido que salio bien */
		if (pid == -1)
		{
			perror("Error: fork");
			return (0);
		}
		/* valido que fue exito*/
		if (pid == 0)
		{
			/*ejacutamos el programa y validamos si fallo*/
			if (execve(comando, av, environ) == -1)
				perror("Error: execve");
		}
		else
		{
			/* status se encarga de ver si el hijo termino correctamente*/
			wait(&status);
			/*if (actual_comando != NULL)
				free(actual_comando);*/
			return (0);
		}
	}
	return (0);
}
