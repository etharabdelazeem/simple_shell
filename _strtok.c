#include "shell.h"

/**
 * _strtok - my own strtok function
 * @str: string to tokenize
 * @delim: delimiter
 * Return: a pointer of next token, if not NULL
 */
char *_strtok(char *str, const char *delim)
{
	static char *ts;
	static char *nt;
	unsigned int i;

	if (str != NULL)
		nt = str;
	ts = nt;
	if (ts == NULL)
		return (NULL);
	for (i = 0; ts[i] != '\0'; i++)
		if (check_delim(ts[i], delim) == 0)
			break;


	if (nt[i] == '\0' || nt[i] == '#')
	{
		nt = NULL;
		return (NULL);
	}
	ts = nt + i;
	nt = ts;
	for (i = 0; nt[i] != '\0'; i++)
		if (check_delim(nt[i], delim) == 1)
			break;


	if (nt[i] == '\0')
		nt = NULL;
	else
	{
		nt[i] = '\0';
		nt = nt + i + 1;
		if (*nt == '\0')
			nt = NULL;
	}
	return (ts);
}

/**
 * check_delim - check if a char is a delimiter or not
 * @ch: the character
 * @str: the string
 * Return: on succes 1 and 0 on failure
 */
unsigned int check_delim(char ch, const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
		if (ch == str[i])
			return (1);


	return (0);
}
