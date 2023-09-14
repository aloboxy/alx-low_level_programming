#include "main.h"

/**
 * print_last_digit - prints the last digit of a number with modulos concept
 * @b: is the int i use for the argument of the function
 * Return: integer value which is the last digit
 */

int print_last_digit(int b)
{
	int digit_last;

	digit_last = b % 10;

	if (digit_last < 0)
		digit_last *= -1;
	_putchar(digit_last + '0');

	return (digit_last);
}
