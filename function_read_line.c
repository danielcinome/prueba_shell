#include "functions.h"

char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	getline(&line, &bufsize, stdin);
	printf("------------------------------ %s\n", line);
	return (line);
}
