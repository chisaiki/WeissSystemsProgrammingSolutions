#include <stdio.h>


int main(int argc, char **argv)
{
	printf("%s arguments: ", argv[0]);

	while (*argv != NULL)
		printf("%s\n", *argv++);
	return 0;
}
