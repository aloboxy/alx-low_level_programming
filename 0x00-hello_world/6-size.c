#include <stdio.h>

/**
 * main- this the void
 * Return- return nothing at the end
 * */

int main(void)
{
	printf("Size of a char: %d byte(s)\n", sizeof(char));
	printf("Size of a long int: %d byte(s)\n", sizeof(long int));
	printf("Size of an init: %d byte(s)\n", sizeof(int));
	printf("Size of a float: %d byte(s)\n", sizeof(float));
	printf("Size of a long long: %d byte(s)\n", sizeof(long long int));

	return (0);

}
