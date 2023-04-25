#include "main.h"


void ejecutar(char **av)
{
    pid_t hijo_pid;
    int status;

    if (av[0] == NULL)
    {
        return;
    }

    if (strcmp(av[0], "exit") == 0)
    {
        exit(0);
    }

    if (strcmp(av[0], "env") == 0)
    {
        env_builtin();
        return;
    }

    hijo_pid = fork();

    if (hijo_pid == -1)
    {
        perror("tsh");
        return;
    }

    if (hijo_pid == 0)
    {
        if (execvp(av[0], av) == -1)
        {
            perror("tsh");
        }
        exit(1);
    }
    else
    {
        do
        {
            waitpid(hijo_pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}
