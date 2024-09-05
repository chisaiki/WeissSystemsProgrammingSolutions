#include <stdio.h>
#include <stdlib.h>

extern char **environ; /*This is defined outside the program so we use extern*/

void main()
{
	char **environ_pointer = environ; /*Set point to the start of the list*/

	while (*environ_pointer != NULL)
	{
		printf("%s\n", *environ_pointer);
		environ_pointer++;
	}
}


