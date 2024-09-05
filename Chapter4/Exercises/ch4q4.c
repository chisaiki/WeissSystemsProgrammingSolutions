#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        fprintf(stderr, "Invalid number of arguments.\nFormat: <yearday2date> <integer number>\n");
        exit(1);
    }

    int number;
    if((number = strtod(argv[1], NULL)) == 0)
    {
        fprintf(stderr, "Error: Invalid input.\n");
        exit(1);
    }


   char newcalenderday[50]; /*Store output date string*/
   time_t date_t;                 
   struct tm *date; /*Structure to contain a calendar date and time broken down into its components*/
   time(&date_t); /*Gets current time and stores into date_t*/
   date = localtime(&date_t); /*Takes time from date_t and converts it to to broken down time*/

   date->tm_mon = 0; /*Set month to January*/
   date->tm_mday = 1 + number; /*Set day to be January 1st then add argument number*/

   
   /*Turn broken down time into prefered format*/
   strftime(newcalenderday, sizeof(newcalenderday), "%B %d, %Y", date); 
   printf("%s", newcalenderday);
}
