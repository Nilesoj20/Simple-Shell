#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    char *array[9999];
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    
    printf("$ ");
    while ((read = getline(&line, &len, stdin)) != -1)
    {
        int words_n = count_words(line);
        char *temp = strtok(line, " \n");

        int i;
        for (i = 0; i < words_n && temp != NULL; i++)
        {
            array[i] = temp;
            temp = strtok(NULL, " \n");
        }
        array[i] = NULL;
        
        if (execve(array[0], &array[0], NULL) == -1)
            perror("Error:");
        
        printf("$ ");
        
        if (line)
            free(line);
    }
    
    return (0);
}
