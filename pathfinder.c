#include "simple_shell.h"
/**
 * pathfinder - Takes PATH string, tokenizes it, then concats with "/" & cmd
 * @cmd: command passed from getline in main
 * Return: new_path for use in cmd_read
 */
char *pathfinder(char *cmd)
{
	char *path = strdup(_getenv("PATH"));
	int i = 0, j = 0;
	char *path_tokens = strtok(path, ":");
	char *path_array[100];
	char *s2 = cmd;
	char *new_path = NULL;
	struct stat buf;

	new_path = malloc(sizeof(char) * 1000);
	if (_getenv("PATH")[0] == ':')
		if (stat(cmd, &buf) == 0)
			return (strdup(cmd));

	while (path_tokens != NULL)
	{
		path_array[i++] = path_tokens;
		path_tokens = strtok(NULL, ":");
	}
	path_array[i] = NULL;
	for (j = 0; path_array[j]; j++)
	{
		strcpy(new_path, path_array[j]);
		strcat(new_path, "/");
		strcat(new_path, s2);

		if (stat(new_path, &buf) == 0)
		{
			free(path);
			return (new_path);
		}

		else
			new_path[0] = 0;
	}
	free(path);
	free(new_path);

	if (stat(cmd, &buf) == 0)
		return (strdup(cmd));
	return (NULL);
}
