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
			perror("Error: hijo");
			return(-1);
		}
		if (hijo == 0)
		{
			printf("#cisfun$ ");
			cont = read_line();
			tokenizado = words(cont, " \n\a\b\r\t\0");
				if (execve(tokenizado[0], tokenizado, NULL) == -1)
				{
						perror("Error: tokenizado");
						return(-1);
				}
		}
		else
		{
			wait(&status);
			sleep(1);
		}
	}
	return (1);
}
