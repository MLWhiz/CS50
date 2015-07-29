/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */

bool binsearch(int value,int values[],int min,int max)
{
    if (max<min)
    {
        return false;
    }
    int mid_pos;
    if ((min+max)%2==0)
        mid_pos=(min+max)/2;
    else
        mid_pos=(min+max-1)/2;
    if (values[mid_pos]>value)
        return binsearch(value,values,min,mid_pos-1);
    else if (values[mid_pos]<value)
        return binsearch(value,values,mid_pos+1,max);
    else
        return true;
}

bool search(int value, int values[], int n)
{
    // TODO: implement a linear searching algorithm
    if (n < 0)
    {
        return false;
    }
    return binsearch(value,values,0,n);
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm: selection sort
    for (int j=0;j<n;j++) 
        {
        int min = values[j];
        int min_index = j;
        for (int i=j; i<n; i++)
        {
            if (values[i] < min)
            {
                min = values[i];
                min_index = i;
            }
        }   
        
        values[min_index] = values[j];
        values[j] = min;
        }
    return;
}
