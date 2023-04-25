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

void ejecutar(char **av);
size_t _strlen(const char *s);
char *_strncpy(char *dest, const char *src, size_t n);
char *locacion(char *comando);
char *_envbuilt(char *env_var);
char **token(char *lineptr , char **av, ssize_t num_char_read);
extern char **environ;
#endif /*MAIN_H*/
