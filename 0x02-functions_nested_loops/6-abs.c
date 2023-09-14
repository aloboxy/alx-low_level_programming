#include "main.h"

/**
 * _abs - computes the absolute value of an integer
 * @n: THe int to be operated upon
 *
 * Return: returns an unsigneed int value to calling function
 */

int _abs(int k)
{
	if (k >= 0)
	{
		return (k);
	}

	else
	{
		k *= -1;
		return (k);
	}
}
