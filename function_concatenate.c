#include "functions.h"

char *concatenate(token_t *h, char *parameter)
{
	token_t *copy = h;
	char *newpath;
	int compare = 0;

	while (copy)
	{
		newpath = str_concat(copy->str, "/");
		newpath = str_concat(newpath, parameter);
		compare = access(newpath, X_OK);
		if (compare == 0)
		{
			return(newpath);
		}
		else
		{
			copy = copy->next;
		}
	}
	return (NULL);
}
