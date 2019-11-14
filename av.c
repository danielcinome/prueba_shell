#include <stdio.h>
int main (__attribute__((unused)) int ac, char *av[])
{
	int i = 0;

	while (av[i] != NULL)
	{
	printf("The av is %s\n", av[i]);
	i++;
	}
 return (0);
}