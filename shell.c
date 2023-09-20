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
	char *input, **cmnd;

	if (argv[1] != NULL)
		read_file(argv[1], argv);
	signal(SIGINT, _signal_);
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
		cmnd = parse_cmd(input);
		if (_strcmp(cmnd[0], "exit") == 0)
		{
			exit_bul(cmnd, input, argv, counter);
		}
		else if (is_builtin(cmnd) == 0)
		{
			st = handle_builtin(cmnd, st);
			free_all(cmnd, input);
			continue;
		}
		else
		{
			st = check_cmd(cmnd, input, counter, argv);

		}
		free_all(cmnd, input);
	}
	return (status);
}
