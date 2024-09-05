#define _GNU_SOURCE

#include "error_exits.h"
#include "common_hdrs.h"
#define FORMAT "%c"

int main(int argc, char **argv)
{
	char formatted_date[200];
	time_t current_time; 
	struct tm *broken_down_time; 

	current_time = time(NULL); /*NULL passed as a parameter lets you get the current time*/

	/*Convert current time into broken-down time*/

	broken_down_time = localtime(&current_time);

	if (broken_down_time == NULL)
	   	//fatal_error(EOVERFLOW, "localtime");
		printf("ERROR\n");

	/*Create string from broken down time using the %c format*/

	if ( 0 == strftime(formatted_date, sizeof(formatted_date), FORMAT, broken_down_time))
	{
		//fatal_error(EXIT_FAILURE, "Conversion to a date-time string failed or produced an empty string \n");
		printf("ERROR\n");
	}

	printf("%s\n", formatted_date);
	return 0;

}
