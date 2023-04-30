#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>

extern char **environ;

int ejecutar(char **av);
char *buscar_ruta(char *comando, int *flag);
char *_envbuilt(char *env_var);
char **tokenizer(char *lineptr);
void _sigint(int signal);
char *_itoa(int n);
void print_env(void);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strlen(char *s);

#endif /*MAIN_H*/
