#include "functions.h"

int main(int argc, char *argv[])
{
	char *cont;
	char **tokenizado;
	int status, val_fd = 0;
	pid_t hijo;
		
	while(1)
	{
		hijo = fork();
		if (hijo == -1)
		{
			perror("Error: hijo");
			return(-1);
		}
		val_fd = isatty(STDIN_FILENO);
printf("%d\n", val_fd);
		if (hijo == 0)
		{
			if (argc == 1)
			{
			if (val_fd != 0)
				printf("#cisfun$ ");
			cont = read_line();
			tokenizado = words(cont, " \n\a\b\r\t\0");
				if (execve(tokenizado[0], tokenizado, NULL) == -1)
				{
					perror(argv[0]);
					if (val_fd == 0)
						kill(hijo, SIGINT);
					return (-1);
				}
			}
		}
		else
		{
			if (val_fd == 0)
				break;
			wait(&status);
		}
	}
	return (1);
}
