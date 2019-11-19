#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct token_s
{
	char *str;
	struct token_s *next;
} token_t;

token_t *add_nodeint_end(token_t **head, char *token);

#endif
