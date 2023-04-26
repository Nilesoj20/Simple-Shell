#include "main.h"
char *locacion(char *comando)
{
	char *path, *path_cp, *path_token, *archivo_path;
	int comando_len, token_len;
	struct stat buffer;

	/*obtener el valor de la variable de entorno PATH*/
	path = getenv("PATH");
	if (path)
	{
	/*hago una copia de ese valor para no modificar original*/
		path_cp = strdup(path);
	/*obtengo el tamño del comando*/
		comando_len = strlen(comando);
	/*divido el valor guardado de path con el delimitador :*/
		path_token = strtok(path_cp, ":");
	/*recorro path_token hasta el final*/
		while (path_token)
		{
	/* obtenemos el tamaño de path_token */
			token_len = strlen(path_token);
	/* creamos espacio donde tentra la ruta completa +2 (/ y \0)*/
			archivo_path = malloc(comando_len + token_len + 2);
	/* copiamos la ruta completa en file_path, luego /, el comando y el caracter nulo */
			strcpy(archivo_path, path_token);
			strcat(archivo_path, "/");
			strcat(archivo_path, comando);
			strcat(archivo_path, "\0");
	/* verificamos si la ruta es valida */
			if (stat(archivo_path, &buffer) == 0)
			{
				free(path_cp);
				/*devuelve la ruta completa*/
				return (archivo_path);
			}
			else {
				/*ya no se necesita si no es valida la ruta*/
				free(archivo_path);
				/*pasa al siguiente token*/
				path_token = strtok(NULL, ":");
			}
		}
		free(path_cp);
	/* verificamos si la ruta es valida y existe en el directorio actual */
		if (stat(comando, &buffer) == 0)
		{
			/*retorna el comando */
			return (comando);
		}
	}
	return (NULL);
}
