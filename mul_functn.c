#include "monty.h"

/**
 * _strcmp - compare 2 strings
 * @s1: str to compare
 * @s2: str to compare
 *
 * Return: 0 if both are equals,else onother int if diff
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;
	if (s1[i] > s2[i])
		return (1);

	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

/**
 * _sch - cheack if char is inside a string
 * @s: str to review
 * @c: char to check
 *
 * Return: 1 on success,else 0 if otherwise
 */

int _sch(char *s, char c)
{
	int cont = 0;

	while (s[cont] == c)
	{
		if (s[cont] == c)
		{
			break;
		}
		cont++;
	}
	if (s[cont] == c)
		return (1);
	else
		return (0);
}

/**
 * _strtoky - split string into tokens
 * @s: string to split
 * @d: delimiters
 *
 * Return: tokens
 *
 */

char *_strtoky(char *s, char *d)
{
	static char *ultimo;
	int i = 0, j = 0;

	if (!s)
		s = ultimo;
	while (s[i] != '\0')
	{
		if (_sch(d, s[i]) == 0 && s[i + 1] == '\0')
		{
			ultimo = s + i + 1;
			*ultimo = '\0';
			ultimo++;
			s = s + j;
			return (s);
		}
		else if (_sch(d, s[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}





