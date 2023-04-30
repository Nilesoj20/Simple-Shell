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
	char *comando = NULL, *actual_comando = NULL;

	comando = av[0];
	/* busca la ruta path antes de pasarlo a execve*/
	actual_comando = buscar_ruta(comando);
	if (actual_comando == NULL)
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
			if (actual_comando != NULL)
				free(actual_comando);
			perror("Error: fork");
			return (0);
		}
		/* valido que fue exito*/
		if (pid == 0)
		{
			/*ejacutamos el programa y validamos si fallo*/
			if (execve(actual_comando, av, environ) == -1)
				perror("Error: execve");
			if (actual_comando != NULL)
				free(actual_comando);
		}
		else
		{
			/* status se encarga de ver si el hijo termino correctamente*/
			wait(&status);
			if (actual_comando != NULL)
				free(actual_comando);
			return (0);
		}
	}
	return (0);
}
