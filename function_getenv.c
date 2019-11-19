#include "functions.h"

char *_getenv(char *name, char **env)
{
	char **save = env;
	char **tokenizado;
	int i = 0;

	while (env[i] != NULL)
	{
		save[i] = env[i];
		i++;
	}
	save[i] = NULL;
	i = 0;
	while (save[i] != NULL)
	{
		tokenizado = words(*(save + i), "=");
		/*printf("%s = %s\n",tokenizado[0], tokenizado[1]);*/
			if (_strcmp(tokenizado[0], name) == 0)
			{
				break;
			}
		i++;
	}
	return (tokenizado[1]);
}
