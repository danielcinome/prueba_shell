#include "functions.h"

int main(void)
{
	char *cont;
	char **tokenizado;
	int status;
	pid_t hijo;

	while(1)
	{
		hijo = fork();
		if (hijo == -1)
		{
			perror("Error:");
			return(-1);
		}
		if (hijo == 0)
		{
			printf("#cisfun$ ");
			cont = read_line();
			tokenizado = words(cont, " \n");
				if (execve(tokenizado[0], tokenizado, NULL) == -1)
				{
        				perror("Error:");
					return(-1);
    				}
		}
		else
		{
			wait(&status);
		}
	}
	return (1);
}
