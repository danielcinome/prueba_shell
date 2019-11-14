#include <stdio.h>
#include <string.h>

char *read_line(void);

char *words(char *line)
{
	char *sep = " ";
	char *word;

	word = strtok(line, sep);
	return (word);
}

int main(void)
{
	char *cont;
	char *arreglo;
	char *sep = " \n";
	printf("$ ");
	cont = read_line();
	arreglo = words(cont);
	while (arreglo != NULL)
	{
		printf("%s\n", arreglo);
		arreglo = strtok(NULL, sep);
	}
	return (0);
}

char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	getline(&line, &bufsize, stdin);
	return line;
}
