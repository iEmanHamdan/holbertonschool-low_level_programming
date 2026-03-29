#include <stdio.h>

/**
 * main - finds and prints the first 98 Fibonacci numbers
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long f1 = 1, f2 = 2, next;
	unsigned long head1, head2, next_head;
	unsigned long tail1, tail2, next_tail;
	int i;

	/* Phase 1: Normal printing until we hit the overflow limit */
	for (i = 1; i <= 91; i++)
	{
		printf("%lu, ", f1);
		next = f1 + f2;
		f1 = f2;
		f2 = next;
	}

	/* Phase 2: Split the massive numbers into Heads and Tails */
	head1 = f1 / 1000000000;
	tail1 = f1 % 1000000000;
	head2 = f2 / 1000000000;
	tail2 = f2 % 1000000000;

	/* Phase 3: Head/Tail addition for the remaining numbers */
	for (i = 92; i <= 98; i++)
	{
		/* Print the head, then strictly 9 digits of the tail */
		printf("%lu%09lu", head1, tail1);
		if (i != 98)
		{
			printf(", ");
		}
		else
		{
			printf("\n");
		}

		/* Calculate the next number with carry-over logic */
		next_tail = tail1 + tail2;
		next_head = head1 + head2 + (next_tail / 1000000000);
		next_tail = next_tail % 1000000000;

		/* Shift variables for the next loop */
		head1 = head2;
		tail1 = tail2;
		head2 = next_head;
		tail2 = next_tail;
	}

	return (0);
}
