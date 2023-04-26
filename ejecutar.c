#include "main.h"

/**
 * ejecutar - ejecuta el comando ingresado por el usuario
 * @av: array de strings, donde cada string es una palabra del input
 *
 * Return: void
 */
void ejecutar(char **av)
{
	pid_t pid;
	int status;
	char *comando = NULL, *actual_comando = NULL;

	/*creo un proceso hijo*/
	pid = fork();
	/* valido que salio bien */
	if (pid == -1)
	{
		perror("Error: fork");
		return;
	}
	/* valido que fue exito*/
	if (pid == 0)
	{
		comando = av[0];
		 /* genera la ruta path antes de pasarlo a execve*/
		actual_comando = buscar_ruta(comando);
		if (actual_comando == NULL)
		{
			printf("Error: comando incorrecto\n");
			return;
		
		}
		/*ejacutamos el programa y validamos si fallo*/
		if (execve(actual_comando, av, NULL) == -1)
			perror("Error: execve");
	}
	else
	{
		/* status se encarga de ver si el hijo termino correctamente*/
		wait(&status);
		/*free(actual_comando);*/
	}
}
