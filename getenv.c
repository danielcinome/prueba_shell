#include "functions.h"


int main(int argc, char *argv[], char **env)
{
	char *value;

	value = _getenv(argv[1], env);
	printf("El valor de %s es %s\n", argv[1], value);
	return (0);
}
