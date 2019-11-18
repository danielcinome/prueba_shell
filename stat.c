#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * main - stat example
 *
 * Return: Always 0.
 */
int main(void)
{
    unsigned int i;
    struct stat st;
    char cwd[1024];

    i = 1;
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        if (stat(cwd, &st) == 0)
        {
            printf("The directory %s WAS FOUND\n", cwd);
        }
        else
        {
            printf("The directory %s NOT FOUND\n", cwd);
        }
        i++;
    }
    return (0);
}