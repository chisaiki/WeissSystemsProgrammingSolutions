#include <stdio.h>
#include <unistd.h>

void main()
{
	char name[4]; /*Declare string to hold returned value*/
	size_t len = 3; 
	int returnvalue;

	returnvalue = gethostname(name, len);

	if (returnvalue == -1)
		perror("gethostname");
	else 
		printf("%s\n", name);
}
