#include "main.h"

char **token(char *lineptr , char **av, ssize_t num_leido)
{
	char *lineptr_cp = NULL;
	const char *delimitador = " \n";
	int num_tokens = 0, i = 0, j = 0;
	char *token;

	/* memoria para la nueva copia de lineptr*/
	lineptr_cp = malloc(sizeof(char) * num_leido);
	/* por si falla malloc*/
	if (lineptr_cp == NULL)
	{
		perror("tsh: memory allocation error");
		return (NULL);
	}
	/*copio lineptr en la copia de reserva lineptr_cp*/
	strcpy(lineptr_cp, lineptr);
	/* dividimos la cadena en base al delimitador*/
	token = strtok(lineptr, delimitador);
	/*cuenta el numero de token y va dividiendo la cadena hasta que no se pueda dividir mas y llega null */
	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delimitador);
	}
	/* PRUEBA*/
	printf(">>TOKEN>>> %d \n", num_tokens);
	/* separamos memoria para el array*/
	av = malloc(sizeof(char *) * num_tokens);
	/* divide la cadena lineptr_cp en subcadenas mas pequeñas*/
	token = strtok(lineptr_cp, delimitador);
	/*memoria para las subcadenas que fueron divididos y se copia en el indice i del array */
	 for (i = 0; token != NULL; i++)
	 {
		 av[i] = malloc(sizeof(char) * strlen(token));
		 if (av[i] == NULL)
		 {
			for (j = i; j >= 0; j--)
			{
				free(av[j]);
			}
			 free(av);
		 }
		 strcpy(av[i], token);
		 token = strtok(NULL, delimitador);
	/*PRUEBA*/
		 printf(">>ARRAY>>> %s \n", av[i]);
	 }
	 /* en la ultima iteracion le damos el valor null para el fin */
	 av[i] = NULL;
	 /*retorno av para utilizarla en el main.c*/
	 return (av);
}
