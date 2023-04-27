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

int ejecutar(char **av);
size_t _strlen(const char *s);
char *_strncpy(char *dest, const char *src, size_t n);
char *buscar_ruta(char *comando);
char *_envbuilt(char *env_var);
char **token(ssize_t num_leido, char *lineptr);
extern char **environ;
void _sigint(int signal);
#endif /*MAIN_H*/
