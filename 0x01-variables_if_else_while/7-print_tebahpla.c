#include<stdio.h>
/**
 * main -Entry point
 *
 * Return: 0 (success)
 */
int main(void)
{
	char lettr;

	for (lettr = 'z'; lettr >= 'a'; lettr--)
		putchar(lettr);
	putchar('\n');
	return (0);
}
