#include "shell.h"

/**
 * _signal_ - not to exit by ^C
 * @signal: the signal
 * Return: nothing
 */
void _signal_(int signal)
{
	if (signal == SIGINT)
	{
		PRINTER("\n$ ");
	}
}
