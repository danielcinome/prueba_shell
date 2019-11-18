#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

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
		printf("%s = %s\n", tokenizado[0], tokenizado[1]);
		if (*tokenizado[0] == *name)
		{
			break;
		}
	i++;
	}
	return(*tokenizado[1]);
}

int main (void)
{
	char *value;

	value = _getenv("WD");
	printf("El valor de PWD es %s\n", value);
	return(0);
}