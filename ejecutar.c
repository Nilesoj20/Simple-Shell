#include "main.h"

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
		perror ("Error: fork");
		return;
	}
	/* valido que fue exito*/
	if (pid == 0)
	 {
		comando = av[0];
		 /* genera la ruta path antes de pasarlo a execve*/
		actual_comando = locacion(comando);
		/*ejacutamos el programa y validamos si fallo*/
	 	if (execve(actual_comando, av, NULL) == -1)
		{
			perror("Error: execve");
	 	}
		/*termina si el proceso hijo falla*/
		exit(EXIT_FAILURE);
	 }
	else {
		printf("antes del wait\n");
		/* status se encarga de ver si el hijo termino correctamente*/
		wait(&status);
		/*obtenemos el valor de retorno del phijo y asignalo a status */
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		printf("yo soy el padre\n");
	}
}
