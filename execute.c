#include "shell.h"

/**
 * handle_builtin - selects which command to execute
 * @cmd: the command string
 * @er: last command data
 * Return: 0 on success, -1 on failure
 */

int handle_builtin(char **cmd, int er)
{
	 bul_t bil[] = {
		{"cd", change_dir},
		{"env", dis_env},
		{"help", display_help},
		{"echo", echo_bul},
		{"history", history_dis},
		{NULL, NULL}
	};
	int i = 0;

	while ((bil + i)->command)
	{
		if (_strcmp(cmd[0], (bil + i)->command) == 0)
			return ((bil + i)->fun(cmd, er));
		i++;
	}
	return (-1);
}
/**
 * check_cmd - (Fork, Wait & Excute) commands
 * @cmd: the command string
 * @input: input string 
 * @c: number to be printed for error
 * @argv: Argument Vector 
 * Return: 1 on Null command, -1 if not found
 *    ,0 on successful execution
 */
int check_cmd(char **cmd, char *input, int c, char **argv)
{
	int status;
	pid_t pid;

	if (*cmd == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
			path_cmd(cmd);

		if (execve(*cmd, cmd, environ) == -1)
		{
			print_error(cmd[0], c, argv);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}

		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
