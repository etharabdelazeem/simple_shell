#include "shell.h"

/**
 * main - our main fuction to mimic the unix shell
 * @argc:count of arguments
 * @argv:vector of arguments
 * Return:the exit status
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	int counter = 0, status = 1, st = 0;
	char *input, **command;

	if (argv[1] != NULL)
		read_file(argv[1], argv);
	signal(SIGINT, signal_to_handel);
	while (status)
	{
		counter++;
		if (isatty(STDIN_FILENO))
			prompt();
		input = _getline();
		if (input[0] == '\0')
		{
			continue;
		}
		history(input);
		cmd = parse_cmd(input);
		if (_strcmp(cmd[0], "exit") == 0)
		{
			exit_bul(cmd, input, argv, counter);
		}
		else if (is_builtin(cmd) == 0)
		{
			st = handle_builtin(cmd, st);
			free_all(cmd, input);
			continue;
		}
		else
		{
			st = check_cmd(cmd, input, counter, argv);

		}
		free_all(cmd, input);
	}
	return (statue);
}
/**
 * is_builtin - is the command a builtin
 *
 * @comd:the entered command
 * Return: zero on success, -1 otherwise
 */
int is_builtin(char **comd)
{
	bul_t fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int i = 0;
		if (*comd == NULL)
	{
		return (-1);
	}

	while ((fun + i)->command)
	{
		if (_strcmp(comd[0], (fun + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}
/**
 * create_env - duplicates the environment variable
 * @env: the environment variable
 * Return: Nothing
 */
void create_env(char **env)
{
	int i;

	for (i = 0; environ[i]; i++)
		env[i] = _strdup(environ[i]);
	env[i] = NULL;
}
