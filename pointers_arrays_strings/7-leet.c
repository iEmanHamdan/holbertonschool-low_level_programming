#include "main.h"

/**
 * leet - encodes a string into 1337
 * @s: string to encode
 *
 * Return: pointer to encoded string
 */
char *leet(char *s)
{
	int i, j;
	char r[] = "aAeEoOtTlL";
	char l[] = "4433007711";

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; r[j] != '\0'; j++)
		{
			if (s[i] == r[j])
			{
				s[i] = l[j];
			}
		}
	}

	return (s);
}
