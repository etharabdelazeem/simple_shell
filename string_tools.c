#include "shell.h"

/**
 * _strncmp - compares a specific amount n of string one to string two
 * @s1: the first string
 * @s2: the second string
 * @n: the amount of characters to compare
 * Return: 1 If The Strings Don't Match Otherwise 0
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (s1 == NULL)
		return (-1);
	for (i = 0; i < n && s2[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			return (1);
		}
	}
	return (0);
}

/**
 *_strchr - find a character in a string
 * @s:the string to be searched in
 * @c:the character to be looked for
 *
 * Return: a pointer to the location of the string
 */
char *_strchr(char *s, char c)
{

	do {
		if (*s == c)
			break;
	} while (*s++);

	return (s);
}

/**
 * _strcat - function to concatinate two strings
 * @dest:the destination string
 * @src: the source string
 *
 * Return:a pointer to the resulting string
 */
char *_strcat(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
}

/**
 * _strcpy - function to copy a src string to a destination string
 * @src: the first string
 * @dest: the second string
 * Return: a pointer to the destination string
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strdup - function to duplicate(repeat) a string
 * @str: the str to be duplicated
 *
 * Return: a pointer to the new, duplicated string
 */
char *_strdup(char *str)
{
	size_t len, i;
	char *str2;

	len = _strlen(str);
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
	{
		return (NULL);
	}

	for (i = 0; i <= len; i++)
	{
		str2[i] = str[i];
	}

	return (str2);
}
