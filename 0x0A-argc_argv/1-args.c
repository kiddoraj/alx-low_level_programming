#include "main.h"
#include<stdio.h>
/**
 *main - prints the number of arguments passed into it
 *@argc:number of arguments
 *@argv:array
 *
 *Return: 0
 */
int main(int argc, char *argv[])
{
	int i;
	for (i = 0; i < argc; i++)
	{
		printf("argv = %s\n", argv[i]);
	}
	return (0);
}
