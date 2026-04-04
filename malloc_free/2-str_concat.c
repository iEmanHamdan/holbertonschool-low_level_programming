#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to the new string, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *concat;
	unsigned int i, j, len1 = 0, len2 = 0;

	/* Treat NULL as empty string */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* Measure both strings */
	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;

	/* Allocate space for both strings + null terminator */
	concat = malloc(sizeof(char) * (len1 + len2 + 1));

	if (concat == NULL)
		return (NULL);

	/* Copy s1 */
	for (i = 0; i < len1; i++)
		concat[i] = s1[i];

	/* Copy s2 */
	for (j = 0; j < len2; j++, i++)
		concat[i] = s2[j];

	/* Add null terminator */
	concat[i] = '\0';

	return (concat);
}
