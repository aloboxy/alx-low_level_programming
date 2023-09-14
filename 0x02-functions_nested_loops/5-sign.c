#include "main.h"

/**
 * print_sign - return 0 letter not lowercase, 1 letter lowercase
 *
 * @n : number to check
 * Return: 0 or 1
 *
 */

int print_sign(int n)
{
	int alieu;

	if (n > 0)
	{
		alieu = 1;
		_putchar('+');
	}
	else if (n == 0)
	{
		alieu = 0;
		_putchar('0');
	}
	else
	{
		alieu = -1;
		_putchar('-');
	}
	return (alieu);
}
