/***************************************************************************
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 ***************************************************************************/
 
// standard libraries
#define _XOPEN_SOURCE
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // Check if the right number of argments are supplied. If not tell the user about the arguments needed
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // n is the value of the command line argument specified by the user
    int n = atoi(argv[1]);

    // use srand when a seed has been supplied. argv2 is the seed itself
    // we have to use srand before using drand.
    // if seed has been supplied use it as seed
    // else use a random seed based on time
    
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // for n values generate a random number between 0,1 and multiply it with
    // LIMIT and print it out  
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
