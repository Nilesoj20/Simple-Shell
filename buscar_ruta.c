#include "main.h"
char *buscar_ruta(char *comando)
{
	char *path, *path_cp, *path_token, *ruta_path;
	int comando_len, token_len;
	struct stat buffer;

	/* verificamos si la ruta es valida y existe en el directorio actual */
	if (stat(comando, &buffer) == 0)
		return (comando);

	/*obtener el valor de la variable de entorno PATH*/
	path = getenv("PATH");
	if (path)
	{
	/*hago una copia de ese valor para no modificar original*/
		path_cp = _strdup(path);
	/*obtengo el tamño del comando*/
		comando_len = _strlen(comando);
	/*divido el valor guardado de path con el delimitador :*/
		path_token = strtok(path_cp, ":");
	/*recorro path_token hasta el final*/
		while (path_token)
		{
	/* obtenemos el tamaño de path_token */
			token_len = _strlen(path_token);
	/* creamos espacio donde tentra la ruta completa +2 (/ y \0)*/
			ruta_path = malloc(sizeof(char) * (comando_len + token_len + 2));
	/* copiamos la ruta completa en file_path, luego /, el comando y el caracter nulo */
			sprintf(ruta_path, "%s/%s", path_token, comando);
			ruta_path[comando_len + token_len + 1] = '\0';
	/* verificamos si la ruta es valida */
			if (stat(ruta_path, &buffer) == 0)
			{
				free(path_cp);
				/*devuelve la ruta completa*/
				return (ruta_path);
			}
			else
			{
				/*ya no se necesita si no es valida la ruta*/
				free(ruta_path);
				/*pasa al siguiente token*/
				path_token = strtok(NULL, ":");
			}
		}
		free(path_cp);
	}
	return (NULL);
}
