#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string, or NULL if insufficient memory
 */
char *_strdup(char *str)
{
	char *duplicate;
	unsigned int i, len = 0;

	if (str == NULL)
		return (NULL);

	/* Step 2: Measure the string */
	while (str[len] != '\0')
		len++;

	/* Step 3: Allocate (length + 1 for the null terminator) */
	duplicate = malloc(sizeof(char) * (len + 1));

	/* Safety check */
	if (duplicate == NULL)
		return (NULL);

	/* Step 4: Copy the string */
	for (i = 0; i <= len; i++)
	{
		duplicate[i] = str[i];
	}

	return (duplicate);
}
