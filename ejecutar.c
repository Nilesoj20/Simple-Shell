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
	int status = 0, flag = 0;
	char *comando = NULL, *actual_comando = NULL;

	comando = av[0];
	if (!comando)
		return (1);
	/* busca la ruta path antes de pasarlo a execve*/
	actual_comando = buscar_ruta(comando, &flag);
	if (actual_comando == NULL)
	{
		printf("Error: comando incorrecto\n");
		return (1);
	}
	else
	{
		/*creo un proceso hijo*/
		pid = fork();
		/* valido que salio bien */
		if (pid == -1)
		{
			if (flag == 1)
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
		}
		else
		{
			/* status se encarga de ver si el hijo termino correctamente*/
			wait(&status);
		}
	}
	/* validamos si actual_comando tiene valor*/
	if (flag == 1)
		free(actual_comando);
	return (1);
}
