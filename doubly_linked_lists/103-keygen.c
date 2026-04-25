#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Generates and prints passwords for the crackme5 executable.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char *l = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcURVSQ1riXLIpeYAMjkPnOFR-_XJqcT";
	int len, i, v1, v2, v3, v4;
	char password[7];
	char *name;

	if (argc != 2)
	{
		printf("Usage: %s username\n", argv[0]);
		return (1);
	}

	name = argv[1];
	len = strlen(name);

	password[0] = l[(len ^ 59) & 63];

	v1 = 0;
	for (i = 0; i < len; i++)
		v1 += name[i];
	password[1] = l[(v1 ^ 79) & 63];

	v2 = 1;
	for (i = 0; i < len; i++)
		v2 *= name[i];
	password[2] = l[(v2 ^ 85) & 63];

	v3 = name[0];
	for (i = 0; i < len; i++)
	{
		if (name[i] > v3)
			v3 = name[i];
	}
	srand(v3 ^ 14);
	password[3] = l[rand() & 63];

	v4 = 0;
	for (i = 0; i < len; i++)
		v4 += (name[i] * name[i]);
	password[4] = l[(v4 ^ 239) & 63];

	/* FIXED: Advance PRNG state, then call rand() again */
	for (i = 0; i < name[0]; i++)
		rand();
	password[5] = l[(rand() ^ 229) & 63];

	password[6] = '\0';

	printf("%s", password);
	return (0);
}
