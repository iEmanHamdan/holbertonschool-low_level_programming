#include "main.h"

/**
 * print_times_table - prints the n times table, starting with 0
 * @n: the times table to print
 *
 * Return: void
 */
void print_times_table(int n)
{
	int r, c, prod;

	if (n >= 0 && n <= 15)
	{
		for (r = 0; r <= n; r++)
		{
			for (c = 0; c <= n; c++)
			{
				prod = r * c;
				if (c == 0)
				{
					_putchar(prod + '0');
				}
				else
				{
					_putchar(',');
					_putchar(' ');
					if (prod < 10)
					{
						_putchar(' ');
						_putchar(' ');
						_putchar(prod + '0');
					}
					else if (prod >= 10 && prod < 100)
					{
						_putchar(' ');
						_putchar((prod / 10) + '0');
						_putchar((prod % 10) + '0');
					}
					else
					{
						_putchar((prod / 100) + '0');
						_putchar(((prod / 10) % 10) + '0');
						_putchar((prod % 10) + '0');
					}
				}
			}
			_putchar('\n');
		}
	}
}
