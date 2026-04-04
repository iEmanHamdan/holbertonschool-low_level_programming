#include "main.h"

/**
 * _strncat - concatenates two strings using at most n bytes from src
 * @dest: the string to be appended to
 * @src: the string to append
 * @n: maximum number of bytes to use from src
 *
 * Return: a pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int d_len = 0;
	int i;

	/* Find the end of dest */
	while (dest[d_len] != '\0')
	{
		d_len++;
	}

	/* Copy at most n bytes from src */
	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[d_len] = src[i];
		d_len++;
	}

	/* Always add the terminating null byte */
	dest[d_len] = '\0';

	return (dest);
}
