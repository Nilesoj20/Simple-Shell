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
	int num_tokens = 0, i = 0;
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
	/* verifica si fallo alcanzo EOF o CRTL+D*/
		if (num_leido == -1)
		{
			return (0);
		}
		if (strcmp("exit\n", lineptr) == 0)
		{
			free(lineptr);
			printf("\n");
			return (0);
		}
		lineptr_cp = malloc(sizeof(char) * (num_leido + 1));
		if (lineptr_cp == NULL)
		{
			free(lineptr);
			perror("tsh: memory allocation error");
			return (0);
		}
		strcpy(lineptr_cp, lineptr);
		token = strtok(lineptr, delim);
		while (token != NULL){
			num_tokens++;
			token = strtok(NULL, delim);
		}
			printf(">>TOKEN>>> %d \n", num_tokens);
		av = malloc(sizeof(char *) * (num_tokens + 1));
		token = strtok(lineptr_cp, delim);
		for (i = 0; token != NULL; i++){
			av[i] = token;
			printf(">>ARRAY>>> %s \n", av[i]);
			token = strtok(NULL, delim);
		}
		av[i] = NULL;
		ejecutar(av);
		free(av);
		free(lineptr);
		free(lineptr_cp);
	}
	return(0);
}
