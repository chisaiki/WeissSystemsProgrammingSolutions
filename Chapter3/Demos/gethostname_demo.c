#include <stdio.h>
#include <unistd.h> /*The program needs to include unistd.h because gethostname() is a system
 call. */
#include <errno.h>


void main()
{
	char name[20];
	size_t len = 4; /*The  len  argument  specifies
       the number of bytes in name.  (Thus, name does not require a terminating null byte.)*/
	int returnvalue = 0;

	returnvalue = gethostname(name, len); /*Make get host call*/

	if ( returnvalue == -1)
	{
		switch (errno)
		{
			case EFAULT:
				printf("A bad address was passed for the string name\n");
				break;

			case EINVAL:
				printf("The length argument was negative\n");
				break;

			case ENAMETOOLONG:
			       printf("The hostname is too long for the allocated array.\n");
		       	       break;

		}
	}

	else
		printf("%s\n", name);
}
