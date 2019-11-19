#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct token_s
{
	char *str;
	struct token_s *next;
} token_t;

char *read_line(void);
char **words(char *line, char *sep);
token_t *add_nodeint_end(token_t **head, char *token);

#endif
