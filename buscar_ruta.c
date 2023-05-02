#include "main.h"

/**
 * buscar_ruta - busca un comando en el PATH
 * @comando: comando a buscar en el PATH
 * @flag: indicador de prevención para liberar
 *        la variable ruta_path
 *
 * Return: en éxito - la ruta absoluta del comando,
 *         en error - NULL
 */
char *buscar_ruta(char *comando, int *flag)
{
	char *path = NULL, *path_cp = NULL, *path_token = NULL, *ruta_path = NULL;
	int comando_len = 0, token_len = 0;

	/* Le damos la ruta completa del comando */
	if (open(comando, O_RDONLY) > 0)
		return (comando);
	/*obtener el valor de la variable de entorno PATH*/
	path = getenv("PATH");
	if (path)
	{
		path_cp = _strdup(path);
		if (path_cp == NULL)
			return (NULL);
		comando_len = _strlen(comando);
		path_token = strtok(path_cp, ":");
		while (path_token)
		{
			token_len = _strlen(path_token);
			ruta_path = malloc(sizeof(char) * (comando_len + token_len + 2));
			if (ruta_path == NULL)
			{
				perror("Failed malloc: buscar_ruta.c, línea 31");
				free(path_cp);
				return (NULL);
			}
			sprintf(ruta_path, "%s/%s", path_token, comando);
			ruta_path[comando_len + token_len + 1] = '\0';
			if (open(ruta_path, O_RDONLY) > 0)
			{
				free(path_cp);
				*flag = 1;
				return (ruta_path);
			}
			free(ruta_path);
			ruta_path = NULL;
			path_token = strtok(NULL, ":");
		}
		free(path_cp);
		if (ruta_path)
			*flag = 1;
		return (ruta_path);
	}
	return (NULL);
}
