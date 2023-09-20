#include "shell.h"

/**
 * free_env - free environment variable
 * @env: environment variable array
 * Return: nothing
 */
void free_env(char **env)
{
	int i = 0;

	while (env[i])
		free(env[i++]);

}
