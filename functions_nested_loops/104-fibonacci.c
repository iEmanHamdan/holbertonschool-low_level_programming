#include <stdio.h>

/**
 * main - finds and prints the first 98 Fibonacci numbers
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long f1_h = 0, f1_t = 1;
	unsigned long f2_h = 0, f2_t = 2;
	unsigned long n_h, n_t;
	int i;

	for (i = 1; i <= 98; i++)
	{
		if (f1_h == 0)
		{
			printf("%lu", f1_t);
		}
		else
		{
			printf("%lu%09lu", f1_h, f1_t);
		}

		if (i != 98)
		{
			printf(", ");
		}
		else
		{
			printf("\n");
		}

		n_t = f1_t + f2_t;
		n_h = f1_h + f2_h;

		if (n_t >= 1000000000UL)
		{
			n_h += 1;
			n_t %= 1000000000UL;
		}

		f1_h = f2_h;
		f1_t = f2_t;
		f2_h = n_h;
		f2_t = n_t;
	}

	return (0);
}
