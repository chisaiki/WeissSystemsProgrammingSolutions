#include <stdio.h>
#include <unistd.h>

#define _POSIX_HOST_NAME_MAX 255

/*NOTE:  {_POSIX_HOST_NAME_MAX}
             Maximum length of a host name (not including the terminating null) as returned  from  the  gethostname()
             function.
             Value: 255*/
void main()
{
	char name[ _POSIX_HOST_NAME_MAX ]; /*Declare string to hold returned value*/
	size_t len = _POSIX_HOST_NAME_MAX; /*Specifies the number of bytes in name*/
	/*Every character takes up one byte.*/ 
	
	int returnvalue;

	returnvalue = gethostname(name, len);

	if (returnvalue == -1)
		perror("gethostname");
	else 
		printf("%s\n", name);
}
