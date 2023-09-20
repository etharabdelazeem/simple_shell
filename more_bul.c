#include "shell.h"

/**
 * history_dis - display user history
 * @cmd: the command
 * @er: last command data
 * Return: 0 on succes, -1 on failure
 */
int history_dis(char **cmd, int er)
{
	char *filename = ".simple_shell_history";
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;
	char *er;
	(void) cmd;
	(void) er;

	fp = fopen(filename, "r");
	if (fp == NULL)
		return (-1);

	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		er = _itoa(counter);
		PRINTER(er);
		free(er);
		PRINTER(" ");
		PRINTER(line);

	}
	if (line)
		free(line);

	fclose(fp);

	return (0);
}
/**
 * print_echo - execute echo
 * @cmd: command string
 * Return: 0 on succes, -1 on failure
 */
int print_echo(char **cmd)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve("/bin/echo", cmd, environ) == -1)
			return (-1);

			exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
			return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
