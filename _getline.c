#include "shell.h"

/**
 * _getline - a function that accepts user input
 * Return: a string containing user input
 */
char *_getline()
{
	int i, buffsize = BUFSIZE, rd;
	char c = 0;
	char *buff = malloc(buffsize);

	if (buff == NULL)
		return (NULL);

	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			if (buff)
				free(buff);
			exit(EXIT_SUCCESS);
		}

		buff[i] = c;
		if (buff[0] == '\n')
		{
			if (buff)
				free(buff);
			return ("\0");
		}
		if (i >= buffsize)
		{
			buff = _realloc(buff, buffsize, buffsize + 1);
			if (buff == NULL)
				return (NULL);
		}
	}


	buff[i] = '\0';
	hashtag_handle(buff);
	return (buff);
}

/**
 * hashtag_handle - remove comments start with #
 * @buff: a buffer that holds string
 * Return: nothing
 */
void hashtag_handle(char *buff)
{
	int i;

	for (i = 0; buff[i] != '\0'; i++)
	{
		if (buff[i] == '#')
		{
			buff[i] = '\0';
			break;
		}
	}
}
