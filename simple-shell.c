#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	getline(&line, &bufsize, stdin);
	return line;
}

char **words(char *line)
{
	char *sep = " \n";
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


int main(void)
{
	char *cont;
	char **tokenizado;
	int status;
	pid_t hijo;

	while(1)
	{
		hijo = fork();
		if (hijo == -1)
		{
			perror("Error:");
			return(-1);
		}
		if (hijo == 0)
		{
			printf("#cisfun$ ");
			cont = read_line();
			tokenizado = words(cont);
				if (execve(tokenizado[0], tokenizado, NULL) == -1)
				{
        				perror("Error:");
					return(-1);
    				}
		}
		else
		{
			wait(&status);
		}
	}
	return (1);
}
