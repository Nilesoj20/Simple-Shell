#include "main.h"
/**
 * main - main function
 * @ac: argument count
 * @av: argument vector
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	char *prompt = "Nilisoj $ ";
	char *lineptr = NULL, *lineptr_cp = NULL;
	ssize_t num_leido;
	size_t n = 0;
	const char *delim = " \n";
	int num_tokens = 0, i = 0, j = 0;
	char *token;

	/* casteo ac para no tener problemas*/
	(void)ac;

	/* Creo un loop infinito*/
	while (1)
	{
		/* comando para saber si entro en modo interactivo*/
		if (isatty(0))
			printf("%s", prompt);
	/* leo la linea con getline*/
		num_leido = getline(&lineptr, &n, stdin);
	/* verifica si fallo o alcanzo EOF o CRTL+D*/
		if (num_leido == -1 || strcmp("exit\n", lineptr) == 0)
		{
			free(lineptr);
			return (-1);
		}
		lineptr_cp = malloc(sizeof(char) * num_leido);
		if (lineptr_cp == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}
		strcpy(lineptr_cp, lineptr);
		token = strtok(lineptr, delim);
		while (token != NULL){
			num_tokens++;
			token = strtok(NULL, delim);
		}
			printf(">>TOKEN>>> %d \n", num_tokens);
		av = malloc(sizeof(char *) * num_tokens);
		token = strtok(lineptr_cp, delim);
		for (i = 0; token != NULL; i++){
			av[i] = malloc(sizeof(char) * strlen(token));
			if (av[i] == NULL)
			{
				for (j = i; j >= 0; j--)
				{
					 free(av[j]);
				}

			}
			strcpy(av[i], token);
			printf(">>ARRAY>>> %s \n", av[i]);
			token = strtok(NULL, delim);
		}
		av[i] = NULL;
		ejecutar(av);
	}
	/* libero la memoria allocada*/
	free(lineptr_cp);
	free(lineptr);
	return(0);
}
