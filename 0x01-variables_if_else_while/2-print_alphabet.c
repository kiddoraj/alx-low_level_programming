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
	putchar('\n');
	return (0);

}
