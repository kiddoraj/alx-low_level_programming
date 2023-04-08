#include "main.h"
#include<stdio.h>

/**
 *atoi - converts string to an interger
 *@s:string
 *
 *Return: int
 */
int _atoi(char *s)
{
	int a, b, c, d, len, dgt;

	a= b = c = d = len = dgt = 0;

	while (s[len] != '\0')
		len++;
	while (a < len && d == 0)
	{
		if (s[a] == '-')
			b++;
		if (s[a] >= '0' && s[a] <= '9')
		{
			dgt = s[a] - '0';
			if (b % 2)
				dgt =- dgt;
			c = c * 10 + dgt;
			d = 1;
			if (s[a + 1] < '0' || s[a + 1] > '9')
				break;
			d = 0;
		}
		a++;
	}
	if (d == 0)
		return (0);
	return (c);
}



/**
 *main - multiplies two numbers
 *@argc: number of arg
 *@argv:array
 *
 *Return: 0 
 */
int main(int argc, char *argv[])
{
	int num1, num2, rslt;

	if (argc < 3 || argc > 3)
	{
		printf("Error\n");
		return (1);
	}
	num1 = _atoi(argv[1]);
	num2 = _atoi(argv[2]);
	rslt = num1 * num2;
	printf("%d\n", rslt);
	return (0);
}

	
