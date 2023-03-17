#include<stdio.h>
/**
 * main -Entry point
 *
 * Return: 0 (success)
 */
int main(void)
{
	int n;
	char lettr;

	for (n = 0; n < 10; n++)
		putchar((n % 10) + '0');
	for (lettr = 'a'; lettr <= 'f'; lettr++)
		putchar(lettr);
	putchar ('\n');
	return (0);
}
