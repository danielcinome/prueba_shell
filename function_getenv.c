#include "functions.h"

char *_getenv(char *name)
{
	extern char **environ;
	char **save = environ;
	char **tokenizado;
	int i = 0;

	while (environ[i] != NULL)
	{
        	save[i] = environ[i];
        	i++;
		
    	}
	save[i] = NULL;
	i = 0;
	while(save[i] != NULL)
	{
		tokenizado = words(*(save + i), "=");
		printf("%s = %s\n",tokenizado[0], tokenizado[1]);
		if (_strcmp(tokenizado[0], name) == 0)
		{
			break;
		}
	i++;
	}
	return(tokenizado[1]);
}
