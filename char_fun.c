#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strlen - return length of a string
 * @s: points to array of chars
 * Description: does the job
 *
 * Return: the length
 */
int _strlen(char *s)
{
	int count = 0;

	while (*(s + count) != '\0')
		count++;
	return (count);

}

/**
 * _strncpy - copies a part only
 * @dest: a pointer to destination array
 * @src: a pointer to source array
 * @n: an input integer indicating how much to append
 * Description: copies n characters of source into dest
 *
 * Return: pointer to source
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (n)
	{
		if (src[i] == '\0')
			break;
		*(dest + i) = src[i];
		i++;
		n--;
	}
	while (n)
	{
		*(dest + i) = '\0';
		i++;
		n--;
	}
	return (dest);
}

/**
 * _puts - print sentence
 * @str: pointer of array
 * Descripton: neck hurts
 *
 * Return: void
 */
void _puts(char *str)
{
	int count = 0;

	while (*(str + count) != '\0')
	{
		_putchar(*(str + count));
		count++;
	}
	_putchar('\n');
}

/**
 * _atoi - function
 * @s: pointer to array
 * Description: oooh
 *
 * Return: an int
 */
int _atoi(char *s)
{
	unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, i;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;

		if (*(s + count) == '-')
			pn *= -1;

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		oi = oi + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}
