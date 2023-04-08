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
 *main - adds positive numbers
 *@argc: number of arg
 *@argv:array
 *
 *Return: 0
 */
int main(int argc, char *argv[])
{
	int i, j, k, sum, num;

	sum = 0;

	for (i = 0; i < argc; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (!(argv[i][j] >= '0' || argv[i][j] <= '9'))
			{
				puts("Error");
				return (1);
			}
		}
	}
	for (k = 1; k < argc; k++)
	{
		num = _atoi(argv[k]);
		if (num >= 0)
		{
			sum += num;
		}
	}
	printf("%d\n", sum);
	return (0);
}
