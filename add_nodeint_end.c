#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

/**
* add_nodeint_end - function that adds a new node at the end of a list.
* @head : pointer to head
* @n : intger
* Return: the address of the new element, or NULL if it failed
*/

token_t *add_nodeint_end(token_t **head, char *token)
{
	token_t *new;
	token_t *aux;

	new = malloc(sizeof(token_t));
	if (new == NULL)
		return (NULL);

	aux = *head;
	new->str = token;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		while (aux->next != NULL)
			aux = aux->next;

		aux->next = new;
	}

	return (new);
}
