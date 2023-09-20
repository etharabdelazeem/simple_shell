#include "shell.h"

/**
 * _itoa - a function to convert an integer to a char
 * @n: the integer that is to;be converted
 *
 * Return: a pointer to the chat
 */
char *_itoa(unsigned int n)
{
	int len = 0, i = 0;
	char *s;

	len = intlen(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	s[i] = (n % 10) + '0';
	array_rev(s, len);
	s[i + 1] = '\0';
	return (s);
}

/**
 * _strcmp - function to compare two input strings
 * @s1: the string to compare
 * @s2: the string to compare to
 * Return: zero if identical and the difference otherwise
 */
int _strcmp(char *s1, char *s2)
{
int cmp = 0, i, len1, len2;
len1 = _strlen(s1);
len2 = _strlen(s2);

	if (s1 == NULL || s2 == NULL)
		return (1);
	if (len1 != len2)
		return (1);
	for (i = 0; s1[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			cmp = s1[i] - s2[i];
			break;
		}
		else
			continue;
	}
	return (cmp);
}

/**
 * _isalpha - sees if c is an alphabet char
 *@c:the character to be checked for
 * Return: one if it is otherwise zero
 */
int _isalpha(int c)
{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * intlen - counts the length of an intger
 * @num: the intger to;be counted
 *
 * Return: the length of the intger
 */
int intlen(int num)
{
	int len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

/**
 *  array_rev - reverses the given array
 * @arr: the given array
 * @len: the length of `the given array
 *
 * Return:nothing
 */
void array_rev(char *arr, int len)
{
	int i;
	char tmp;

	for (i = 0; i < (len / 2); i++)
	{
		tmp = arr[i];
		arr[i] = arr[(len - 1) - i];
		arr[(len - 1) - i] = tmp;
	}
}
