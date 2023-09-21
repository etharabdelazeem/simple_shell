#include "shell.h"

/**
 * _realloc - reallocate with different size
 * @ptr: pointer to previosly allocated array
 * @old_size: the old size in bytes
 * @new_size: the new size in bytes
 * Return: pointer to different array or NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *s;
	unsigned int i, x = old_size;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (old_size == new_size)
		return (ptr);
	s = malloc(new_size);
	if (s == NULL)
		return (NULL);
	if (ptr == NULL)
		return (s);
	if (old_size > new_size)
	{
		x = new_size;
	}
	for (i = 0; i < x; i++)
	{
		s[i] = *((char *)ptr + i);
	}

	free(ptr);
	return (s);

}

/**
 * _calloc - allocates an array
 * @size: size of the array
 * Return: pointer
 */
void *_calloc(unsigned int size)
{
	char *a;
	unsigned int i;

	if (size == 0)
	return (NULL);
	a = malloc(size);
	if (a == NULL)
	return (NULL);
	for (i = 0; i < size; i++)
	{
		a[i] = '\0';
	}
	return (a);
}

/**
 * free_all - free command and line
 * @cmd: pointer of array
 * @line: pointer to string
 * Return: nothing
 */
void free_all(char **cmd, char *line)
{
	if (cmd)
		free(cmd);
	if (line)
		free(line);


	cmd = NULL;
	line = NULL;
}

/**
 * _memcpy - copy an amount n from source to dest
 * @dest: destination array
 * @src: source array
 * @n: the amount to copy
 * Return: pointer to string
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];

	return (dest);
}


/**
 * fill_an_array - initialize an array
 * @ptr: pointer of the array
 * @n: the int to fill
 * @len: the length of array
 * Return: void pointer
 */
void *fill_an_array(void *ptr, int n, unsigned int len)
{
	char *p = ptr;
	unsigned int i = 0;

	while (i < len)
	{
		*p = n;
		p++;
		i++;
	}
	return (ptr);
}
