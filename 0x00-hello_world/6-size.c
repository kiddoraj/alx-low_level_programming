#include<stdio.h>
/**
 * main -Entry point
 *
 * Return: Always 0 (Sucess)
 */
int main(void)
{
	printf("size of a char:%ibyte(s)\n", sizeof(char));
	printf("size of a int:%ibyte(s)\n", sizeof(int));
	printf("size of a long int:%ibyte(s)\n", sizeof(long int));
	printf("size of a long long int:%ibyte(s)\n", sizeof(long long int));
	printf("size of a float:%ibyte(s)\n", sizeof(float));
	return (0);
}
