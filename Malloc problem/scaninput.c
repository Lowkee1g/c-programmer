#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **array;

int main(void)
{
    // create an initial array of 10 strings
    array = malloc(10 * sizeof(char *));
    if (array == NULL)
    {
        // handle allocation error
    }

    for (int i = 0; i < 10; i++)
    {
        // allocate memory for each string in the array
        array[i] = malloc(100 * sizeof(char));
        if (array[i] == NULL)
        {
            // handle allocation error
        }
        strcpy(array[i], "hello world"); // initialize the string with some value
    }

    // resize the array to store 20 strings
    array = realloc(array, 20 * sizeof(char *));
    if (array == NULL)
    {
        // handle allocation error
    }

    for (int i = 10; i < 20; i++)
    {
        // allocate memory for each additional string in the array
        array[i] = malloc(100 * sizeof(char));
        if (array[i] == NULL)
        {
            // handle allocation error
        }
        strcpy(array[i], "hello world"); // initialize the string with some value
    }

    // use the array of strings

    // free memory when no longer needed
    for (int i = 0; i < 20; i++)
    {
        free(array[i]); // free memory for each string in the array
    }
    free(array); // free memory for the array itself

    return 0;
}
