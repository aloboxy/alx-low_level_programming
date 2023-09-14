#include "main.h"

/**
 * _islower - check for lower case letter if Yes it returns 1
 * @c : character to check the case
 * Return : 0  if successful. _islower - Entry point 
 */

int _islower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}
