#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		fprintf(stderr, "Error: Not enough arguments inputted.\n");
		exit(EXIT_FAILURE);
	}

	for (int i = argc - 1; i > 0; i--)
	{
		printf("%s\n", argv[i]);
	}

	exit(EXIT_SUCCESS);
}
