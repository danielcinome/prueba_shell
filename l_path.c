#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "functions.h"
int _strlen(char *s)
{
	char *a = s;

	while (*a)
	{
	++a;
	}
return (a - s);
}

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
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while ((s1[i] != '\0' && s2[i] != '\0') && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
void print_listint(token_t *h)
{
	token_t *copy = h;
	char *newpath;
	while (copy)
	{
		newpath = str_concat(copy->str, "/ls");
		printf("%s\n", newpath);
		copy = copy->next;
	}
}
int main (__attribute__((unused)) int argc,__attribute__((unused)) char *argv[], char **env)
{
	char *value;
	char **token;
	token_t *head;
	int i = 0;

	value = _getenv("PATH", env);
	token = words(value, ":");
	head = NULL;
	while (token[i])
	{
		add_nodeint_end(&head, token[i]);
		i++;
	}
		print_listint(head);
	return(0);
}
