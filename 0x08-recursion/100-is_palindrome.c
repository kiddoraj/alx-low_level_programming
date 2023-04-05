#include "main.h"

int chk_pali(char *s, int i, int len);
int _strlen_recursion(char *s);
/**
 *is_palindrome - returns 1 if a string is palindrome
 *@s:string
 *
 *Return: 1 if s == palindrome
 */
int is_palindrome(char *s)
{
	if (*s == 0)
		return (1);
	return (chk_pali(s, 0, _strlen_recursion(s)));
}

/**
 * _strlen_recursion - returns the length of a string
 * @s: string
 *
 * Return: length of the string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen_recursion(s + 1));
}

/**
 * chk_pali - checks the characters recursively for palindrome
 * @s: string 
 * @i: iterator
 * @len: length of the string
 *
 * Return: 1 if palindrome, 0 if not
 */

int chk_pali(char *s, int i, int len)
{
	if (*(s + i) != *(s + len - 1))
		return (0);
	if (i >= len)
		return (1);
	return (chk_pali(s, i + 1, len - 1));
}
