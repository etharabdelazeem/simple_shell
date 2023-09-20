#include "shell.h"

/**
 * print_error - prints the error messages
 * @input:the input receivedx from the user
 * @counter: the counter of lines
 * @argv:the arguments vector
 * Return: Nothing
 */
void print_error(char *input, int counter, char **argv)
{
	char *er;

	PRINTER(argv[0]);
	PRINTER(": ");
	er = _itoa(counter);
	PRINTER(er);
	free(er);
	PRINTER(": ");
	PRINTER(input);
	PRINTER(": not found\n");
}

/**
 * prompt - prints out the prompt message
 * Return: Nothing
 */
void prompt(void)
{
	PRINTER("$ ");
}

/**
 * is_builtin - check builtin
 * @comd:the entered command
 * Return: Zero upon success and -1 otherwise
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
