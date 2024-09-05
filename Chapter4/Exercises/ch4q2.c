/*Need to test this program!*/
/*Runtime = O(n^2)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selectionSort(char **array, int argc);

int main(int argc, char **argv)
{
    if(argc < 3)
    {
        fprintf(stderr, "Error: Not enough arguments\n.");
        exit(1);
    }

    selectionSort(argv, argc);

    for(int i = 1; i < argc; i++)
    {
         printf("%s\n", argv[i]);
    }
}

void selectionSort(char **array, int argc)
{
    /*Used to keep track of the index of the smallest string found during search*/
    int smallest_index;

    /*Used to hold the smallest string*/
    char *smallestWord = malloc(sizeof(char) * 4);

    /*Used as temporary variable used during swaps*/
    char *temporary = malloc(sizeof(char) * 4); 

    for(int i = 1; i < argc - 1; i++)
    {
        smallest_index = i; 

        /*Assume that the current index's string is the smallest*/
        strcpy(smallestWord, array[i]);

        /*Second loop is used to find the actual smallest string*/
        for(int j = i + 1; j < argc; j++)
        {
            if(strcoll(smallestWord, array[j]) > 0)
            {
                strcpy(smallestWord, array[j]);
                smallest_index = j; 
            }
        }

        /*If current word isn't the smallest, do a swap*/
        if (smallest_index != i)
        {
            strcpy(temporary, array[i]);
            strcpy(array[i], array[smallest_index]);
            strcpy(array[smallest_index], temporary);
        }
        
    }

    free(smallestWord);
    free(temporary);
}
