#include<stdio.h>
/**
 * main -Entry point
 *
 * Return: 0 (success)
 */
int main(void)
{
	char lettr;

	for (lettr = 'a'; lettr <= 'z'; lettr++)
		putchar(lettr);
	for (lettr = 'A'; lettr <= 'Z'; lettr++)
		putchar(lettr);
	putchar('\n');
	return (0);

}
