#include "main.h"
#include<stdio.h>
#include<stdlib.h>
/**
 *main - prints min number of coins
 *@argc:number of arg
 *@argv:array
 *
 *Return:0
 */
int main(int argc, char *argv[])
{
	int i, num, rslt;

	int coins[] = {25, 10, 5, 2, 1};

	if (argc != 2)
	{
		printf("Error");
		return (1);
	}
	num = atoi(argv[1]);
	rslt = 0;
	
	if (num < 0)
	{
		printf("0\n");
		return (0);
	}
	for (i = 0; i < 5 && num >= 0; i++)
	{
		while (num >= coins[i])
		{
			rslt++;
			num -= coins[i];
		}
	}
	printf("%d\n", rslt);
	return (0);
}

