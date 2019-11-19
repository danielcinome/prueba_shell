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

int _strcmp(char *s1, char *s2);
char *_getenv(char *name);
char *read_line(void);
char **words(char *line, char *sep);
token_t *add_nodeint_end(token_t **head, char *token);

#endif
