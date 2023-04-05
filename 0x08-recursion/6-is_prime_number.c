#include "main.h"
/**
 *is_prime_number - returns 1 if the input is a prime number
 *@n:number
 *
 *Return: 1 if n == prime number
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (-1);
	return (rl_prime(n, n-1));
}
/**
 *rl_prime - calculate if a number is a prime recursively
 *@n:number
 *@i:number
 *Return: 1 if n is prime
 */
int rl_prime(int n, int i)
{
	if (i == 1)
		return (1);
	if (n % i == 0 && i > 0)
		return (0);
	return (rl_prime(n, i - 1));
}
