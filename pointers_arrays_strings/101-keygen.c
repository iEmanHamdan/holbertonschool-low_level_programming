#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates a random valid password for 101-crackme
 * The sum of ASCII values in the password must equal 2772
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int sum = 0;
	char c;

	srand(time(NULL));

	while (sum <= (2772 - 126))
	{
		c = rand() % 126;
		if (c >= 33)
		{
			sum += c;
			putchar(c);
		}
	}

	putchar(2772 - sum);

	return (0);
}
