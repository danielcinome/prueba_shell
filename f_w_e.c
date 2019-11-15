#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
    char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	int status, i = 0;
	pid_t child_pid = 1;
	pid_t my_pid;

	my_pid = getpid();
	while (i < 5 && (child_pid != 0))
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			printf("Error\n");
			return (1);
		}
		wait(&status);
		i++;
		}
	if (child_pid == 0)
	{
		printf("Mi ID es (%u) y mi padre es (%u)\n", getpid(), getppid());
	}
	else
	{
		printf("(%u) %u, I am your father\n", my_pid, child_pid);
	}
	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("Error:");
	}
    return (0);
}
