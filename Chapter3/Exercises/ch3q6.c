#include <stdio.h>
#include <stdlib.h> /*Defines exit() and strtol()*/
#include <errno.h>


int main(int argc, char **argv)
{
	/*Check arguments for any improper usage*/
	if (argc != 3)
	{
		fprintf(stderr, "Invalid number of arguments.\nUsage: seq <start num> <end num>\n");
		exit(EXIT_FAILURE);
	}

	int startnum, endnum;
	char *start_endptr, *end_endptr;
	errno = 0; 
	
	/*I have to use two pointers in order to not have to error check in between strol calls*/


	startnum = strtol(argv[1], &start_endptr, 0);
	endnum = strtol(argv[2], &end_endptr, 0);

	
	/*ERROR CHECKING*/
        if (errno != 0)
        {
                perror("strtol");
                exit(EXIT_FAILURE);
        }


	if (start_endptr == argv[1])
	{
		fprintf(stderr, "No digits were found in '%s'.\n", argv[1]);
		exit(EXIT_FAILURE);
	}


	/*SHould this not be included? Nothing in the prompt mentioned it*/
	if (*start_endptr != '\0')
	{
		 /* There are non-number characters following the number*/
		printf("These proceeding characters were ignored: %s\n", start_endptr);
	}

	

	if (end_endptr == argv[2])
        {
                fprintf(stderr, "No digits were found in '%s'.\n", argv[2]);
                exit(EXIT_FAILURE);
        }

	
	/*SHould this not be included? Nothing in the prompt mentioned it*/
	if (*end_endptr != '\0')
        {
                 /* There are non-number characters following the number*/
                printf("These proceeding characters were ignored: %s\n", end_endptr);
        }

	
	
	if (startnum > endnum || startnum == endnum)
	{
		fprintf(stderr, "Start value is invalid, cannot be greater than or equal to end value.\n");
		exit(EXIT_FAILURE);
	}
	
	
	/*If no errors were found*/
	for (int i = startnum; i <= endnum; i++)
	{
		printf("%d\n", i);
	}

	exit(EXIT_SUCCESS);
	
}
