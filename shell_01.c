#include "functions.h"

int main(int argc, char *argv[], char **env)
{
	char *cont;
	char **tokenizado;
	int status, val_fd = 0, comp = 0;
	char *result;
	pid_t hijo;

	while (1)
	{
		hijo = fork();
		if (hijo == -1)
		{
			perror("Error: hijo");
			return (-1);
		}
		val_fd = isatty(STDIN_FILENO);
		if (hijo == 0)
		{
			if (argc == 1)
			{
				write(1, "#cisfun$ ", 10);
				cont = read_line();
			if (*cont == '\n' || (*cont == -1)) /* enter */
				return (1);
				tokenizado = words(cont, " \n\a\b\r\t\0");
				comp = _strcmp(tokenizado[0], "exit");
				if (comp == 0)
				{
					exit(1);
				}
				if (access(cont,X_OK) == -1)
				{
					result = l_path(cont, env);
					if (execve(result, tokenizado, NULL) == -1)
					{
						perror(argv[0]);
						if (val_fd == 0)
							kill(hijo, SIGINT);
						return (-1);
					}
				}
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
			wait(&status);
			if (val_fd == 0)
			{
				write(1, "#cisfun$ ", 10);
				break;
			}
		}
	}
	return (1);
}
