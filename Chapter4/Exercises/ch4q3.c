#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_longdbl(char *arg, int flags, long double *value, char *msg);
  
int main() 
{
  char arg[50];
  printf("Enter a number: ");
  scanf("%s", arg);
  long double *value = malloc(sizeof(long double));

  char *msg = malloc(sizeof(char) * 4);

  get_longdbl(arg, 0, value, msg);
  printf("Final Result: %Lf\n", *value);
  printf("%s", msg);
	
}


int get_longdbl(char *arg, int flags, long double *value, char *msg)
{
    double result = 0.0; /*Stores integer values*/
    double fractional = 0.0; /*Stores fractional value*/
    int fractional_bool = 0; /*Checks to see if program should start calculating fractional portion*/
    int count = 0; /*Keeps track of how many decimal places to shift right*/
    int is_negative = 0; /*Checks if final value is negative*/

    if(strlen(arg) == 0)
    {
       flags = 0;
       exit(1); 
    }

    for(int i = 0; arg[i] != '\0'; i++)
    {

        /*If program sees a '+' or a '-' as the first character 
        and a digit following it, it should continue as normal*/
        if((arg[0] == '-' || arg[0] == '+') && (arg[i + 1] >= 48 && arg[i + 1] <= 57))
        {
            if(arg[0] == '-')
            is_negative = 1;
        }

        /*If the current character is a non-digit or if the character is another decimal point*/
        else if(((arg[i] >= 48 && arg[i] <= 57) || (arg[i] == 46 && fractional_bool == 0)) == 0)
        {
            if(i > 0)
            flags = 1;
            else
            flags = 0;

            break;
        }

        /*Start calculating the fractional portion if a decimal point is found*/
        if(arg[i] == 46)
            fractional_bool = 1;

        if((arg[i] >= 48 && arg[i] <= 57) && fractional_bool == 0)
		    result = result * 10.0 + (arg[i] - 48);

        else if((arg[i] >= 48 && arg[i] <= 57) && fractional_bool == 1)
        {
            count++;
            fractional = fractional * 10 + (arg[i] - 48);
        }    
	}

    /*Only execute if a fractional portion exists*/
    if(fractional != 0)
    {
        for(int i = 0; i < count; i++)
        fractional = fractional / 10;
    }

    *value = result + fractional;

    if(is_negative == 1)
    *value = *value * -1;

    switch (flags)
    {
    case 0:
        strcpy(msg, "Warning: String is empty or no digits found.\n");
        break;

    case 1: 
        strcpy(msg, "Warning: String has trailing characters.\n");
        break;

    case 2: /*How do i actually check if its too large?*/
        strcpy(msg, "Error: Value too large.\n");
        break;
    
    case 3:
        strcpy(msg, "Error: Value too small.\n");
        break;
    }

    return 0;
}
