#include "shell.h"

/**
 * read_file - use files to read commands
 * @filename: name of the file to open
 * @argv: Argument Vector
 * Return: nothing
 */
void read_file(char *filename, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		treat_file(line, counter, fp, argv);

	}
	if (line)
		free(line);

	fclose(fp);
	exit(0);
}

/**
 * treat_file - take a line and extract command
 * @line: a single line of file
 * @counter: count error
 * @fp: file descriptor
 * @argv: Argument Vector
 * Return : void
 */
void treat_file(char *line, int counter, FILE *fp, char **argv)
{
	char **cmd;
	int st = 0;

	cmd = parse_cmd(line);
/* compare with the word exit */
	if (_strncmp(cmd[0], "exit", 4) == 0)
	{
		exit_bul_for_file(cmd, line, fp);
	}
	else if (is_builtin(cmd) == 0)
	{
		st = handle_builtin(cmd, st);
		if (cmd)
			free(cmd);
	}
		else
	{
		st = check_cmd(cmd, line, counter, argv);
		if (cmd)
			free(cmd);
	}
}

/**
 * exit_bul_for_file - exit shell (file)
 * @line: a single line of the file
 * @cmd: string of the command
 * @fd: file descriptor
 * Return: nothing
 */
void exit_bul_for_file(char **cmd, char *line, FILE *fd)
{
	int statue, i = 0;

	if (cmd[1] == NULL)
	{
		if (line)
			free(line);
		if (cmd)
			free(cmd);
		fclose(fd);
		exit(errno);
	}

	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) < 0)
			perror("illegal number");
	}

	statue = _atoi(cmd[1]);

	if (line)
		free(line);
	if (cmd)
		free(cmd);

	fclose(fd);
	exit(statue);
}
