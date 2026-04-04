#include "main.h"

/**
 * _strncpy - copies a string up to n bytes
 * @dest: destination buffer
 * @src: source string
 * @n: number of bytes to copy
 *
 * Return: pointer to destination string dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	/* Copy characters from src to dest */
	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	/* Fill remaining bytes with null terminators if n > src length */
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}

	return (dest);
}
