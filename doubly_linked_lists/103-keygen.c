#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - generates a valid key for crackme5 based on username
 *
 * @argc: number of command-line arguments
 * @argv: array of command-line argument strings
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	unsigned int i;
	unsigned int len;
	unsigned int idx;
	char *table = "0123456789abcdefghijklmnopqrstuvwxyz"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ+-";

	if (argc != 2)
	{
		printf("Usage: %s username\n", argv[0]);
		return (1);
	}

	len = strlen(argv[1]);

	for (i = 0; i < len; i++)
	{
		idx = ((unsigned char)argv[1][i] ^ (i + len)) & 0x3f;
		printf("%c", table[idx]);
	}

	printf("\n");

	return (0);
}
