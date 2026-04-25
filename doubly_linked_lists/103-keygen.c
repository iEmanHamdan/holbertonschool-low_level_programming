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
	char password[7], *name;
	int len = 0, i, v1, v2, v3, v4, v5;
	char *l = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcURVSQ1riXLIpeYAMjkPnOFR-_XJqcT";

	if (argc != 2)
	{
		printf("Usage: %s username\n", argv[0]);
		return (1);
	}

	name = argv[1];
	len = strlen(name);

	/* Char 1: Length of username XOR 59 */
	password[0] = l[(len ^ 59) & 63];

	/* Char 2: Sum of ASCII values XOR 79 */
	v1 = 0;
	for (i = 0; i < len; i++)
		v1 += name[i];
	password[1] = l[(v1 ^ 79) & 63];

	/* Char 3: Product of ASCII values XOR 85 */
	v2 = 1;
	for (i = 0; i < len; i++)
		v2 *= name[i];
	password[2] = l[(v2 ^ 85) & 63];

	/* Char 4: Max char XOR 14, used to seed rand() */
	v3 = name[0];
	for (i = 0; i < len; i++)
	{
		if (name[i] > v3)
			v3 = name[i];
	}
	srand(v3 ^ 14);
	password[3] = l[rand() & 63];

	/* Char 5: Sum of squares of ASCII values XOR 239 */
	v4 = 0;
	for (i = 0; i < len; i++)
		v4 += (name[i] * name[i]);
	password[4] = l[(v4 ^ 239) & 63];

	/* Char 6: Random seeded by first char XOR 229 */
	for (i = 0; i < name[0]; i++)
		v5 = rand();
	password[5] = l[(v5 ^ 229) & 63];

	password[6] = '\0';

	printf("%s", password);
	return (0);
}
