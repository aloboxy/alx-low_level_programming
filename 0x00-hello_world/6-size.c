#include <stdio.h>

/**
 * main- this the void
 * Return- return nothing at the end
 * */

int main(void)
{
	printf("Size of a char: %lu byte(s)\n", sizeof(char));
	printf("Size of a long int: %lu byte(s)\n", sizeof(long int));
	printf("Size of an init: %lu byte(s)\n", sizeof(int));
	printf("Size of a float: %lu byte(s)\n", sizeof(float));
	printf("Size of a long long: %lu byte(s)\n", sizeof(long long int));

	return (0);

}
