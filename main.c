/**
 * main - main function
 * @ac: argument count
 * @av: argument vector
 * Return: Always 0.
 */
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

extern char **environ;
void env_builtin(void)
{
    char **envp = environ;

    while (*envp != NULL)
    {
        printf("%s\n", *envp);
        envp++;
    }
}

int main()
{
    char *prompt = "Nilisoj $ ";
    char *lineptr = NULL;
    char *lineptr_cp = NULL;
    ssize_t num_leido;
    size_t n = 0;
    const char *delim = " \n";
    int num_tokens = 0, i = 0, j = 0;
    char *token;
    char **av_tmp;

    /* casteo ac para no tener problemas*/
    

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

        av_tmp = malloc(sizeof(char *) * (num_tokens + 1));
        if (av_tmp == NULL)
        {
            perror("tsh: memory allocation error");
            free(lineptr_cp);
            free(lineptr);
            return (-1);
        }

        token = strtok(lineptr_cp, delim);
        for (i = 0; token != NULL; i++){
            av_tmp[i] = malloc(sizeof(char) * (strlen(token) + 1));
            if (av_tmp[i] == NULL)
            {
                perror("tsh: memory allocation error");
                for (j = i - 1; j >= 0; j--)
                {
                    free(av_tmp[j]);
                }
                free(av_tmp);
                free(lineptr_cp);
                free(lineptr);
                return (-1);
            }
            strcpy(av_tmp[i], token);
            printf(">>ARRAY>>> %s \n", av_tmp[i]);
            token = strtok(NULL, delim);
        }
        av_tmp[i] = NULL;

        ejecutar(av_tmp);

         for (i = 0; i < num_tokens; i++) {
            free(av_tmp[i]);
        }
        free(av_tmp);
        free(lineptr_cp);
        free(lineptr);
    }
    return 0;
}
