#include "functions.h"

char **words(char *line, char *sep)
{
	char **tokens = malloc(sizeof(char *) * (*line));
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
