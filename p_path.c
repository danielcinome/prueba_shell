#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char **words(char *line)
{
	char *sep = "=:";
	char **tokens = malloc(sizeof(char *) * 64);
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
	char **token;
	int i = 0;

	token = words(*environ);
	while (*(token + i))
	{
		if (*(token + i) == name)
		{
			i++;
			break;
		}
		else if (*(token + i) == NULL)
		return(NULL);
		else
		{
			i++;
		}
	}
	return(*(token + i));
}

int main (void)
{
	char *value;
	char **token;
	int i = 0;

	value = getenv("PATH");
	token = words(value);
	while (*(token + i))
	{
		printf("%s\n", token[i]);
		i++;
	}
	return(0);
}
