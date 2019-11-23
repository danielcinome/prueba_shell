#include "functions.h"
/**
 * str_concat - This will concatenate two strings
 * @s1: First string
 * @s2: Second string
 * Return: a pointer or NULL
 */
char *str_concat(char *s1, char *s2)
{
	int i, j;
	int tam1, tam2;
	char *dest;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}

	tam1 = _strlen(s1);
	tam2 = _strlen(s2);

	dest = malloc((tam1 + tam2 + 1));

	if (dest == NULL)
	{
		return (NULL);
	}
	else
	{
		for (i = 0; i < tam1; i++)
		{
			dest[i] = s1[i];
		}
		for (j = 0; j <= tam2; j++)
		{
			dest[i + j] = s2[j];
		}
	}
	return (dest);
}
