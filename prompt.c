#include <stdio.h>

char *read_line(void);

int main(void)
{
	char *cont;

	printf("$ ");
	cont = read_line();
	printf("%s", cont);
	return (0);
}

char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	getline(&line, &bufsize, stdin);
	return line;
}
