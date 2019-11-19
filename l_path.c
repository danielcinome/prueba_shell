#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "functions.h"

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while ((s1[i] != '\0' && s2[i] != '\0') && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

char **words(char *line, char *sep)
{
	char **tokens = malloc(sizeof(char *) * 1024);
	char *word;
	int i = 0;

	word = strtok(line, sep);
	while (word != NULL)
	{
		tokens[i] = word;
		i++;
		word = strtok(NULL, sep);
	}
	tokens[i] = NULL;
	return (tokens);
}

char *_getenv(char *name)
{
	extern char **environ;
	char **save = environ;
	char **tokenizado;
	int i = 0;

	while (environ[i] != NULL)
	{
        	save[i] = environ[i];
        	i++;
		
    	}
	save[i] = NULL;
	i = 0;
	while(save[i] != NULL)
	{
		tokenizado = words(*(save + i), "=");
		if (_strcmp(tokenizado[0], name) == 0)
		{
			break;
		}
	i++;
	}
	return(tokenizado[1]);
}
void print_listint(const token_t *h)
{
	while (h)
	{
		printf("%s\n", h->str);
		h = h->next;
	}
}
int main (void)
{
	char *value;
	char **token;
	token_t *head;
	int i = 0;

	value = _getenv("PATH");
	token = words(value, ":");
	head = NULL;
	while (*(token + i))
	{
		add_nodeint_end(&head, token[i]);

		i++;
	}
		print_listint(head);
	return(0);
`}
