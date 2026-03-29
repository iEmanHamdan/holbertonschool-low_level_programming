#include <stdio.h>
#include <math.h>

/**
 * main - finds and prints the largest prime factor of the number 612852475143
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	long int n = 612852475143;
	long int max = -1;
	long int i;

	/* Step 1: Strip out all factors of 2 */
	while (n % 2 == 0)
	{
		max = 2;
		n /= 2;
	}

	/* Step 2: Check odd numbers up to the square root of n */
	for (i = 3; i <= sqrt(n); i += 2)
	{
		while (n % i == 0)
		{
			max = i;
			n = n / i;
		}
	}

	/* Step 3: If n is still greater than 2, it is prime itself */
	if (n > 2)
	{
		max = n;
	}

	printf("%ld\n", max);

	return (0);
}
