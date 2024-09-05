#include <stdio.h>
#include <stdlib.h>

void main()
{
	char *path_to_home;
	path_to_home = getenv("HOME");

	if (path_to_home == NULL)
	{
		printf("The HOME variable is not in the environment\n");
	}

	else 
		printf("Home = %s\n", path_to_home);
}
