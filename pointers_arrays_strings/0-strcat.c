#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: the string to be appended to
 * @src: the string to append
 *
 * Return: a pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int d_len = 0;
	int i = 0;

	/* Find the end of dest */
	while (dest[d_len] != '\0')
	{
		d_len++;
	}

	/* Copy src into dest starting at d_len */
	while (src[i] != '\0')
	{
		dest[d_len] = src[i];
		d_len++;
		i++;
	}

	/* Add the final null terminator */
	dest[d_len] = '\0';

	return (dest);
}
