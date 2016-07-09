/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include<stdio.h>

#include "helpers.h"



// the prototype of the binarysearch
bool binarySearch(int key,int array[],int size,int min,int max);
/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    //search for a needle in the haystack array 
    int min=0;
    int max=n-1;
   
     return binarySearch(value,values,n,min,max);
      
        }

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // sortting using selection sort 
    for(int i=0;i<n;i++)
    {
        int min=i;
         for (int j=i+1;j<=n;j++)
         {
             if(values[j]<values[min])
                  min=j;
                             }
            if(min!=i)
        {
            int temp=values[min];
            values[min]=values[i];
            values[i]=temp;
        }
         
    }
    
    }
   
    // the defination of the binarysearch
    
    bool binarySearch(int key,int array[],int size,int min,int max)
    {
      if (min <= max)
{
    int middle = (min+max)/2;
    if (key == array[middle])
        return true;
    else if (key < array[middle])
      return  binarySearch(key, array, size,min, middle- 1);
    else if (key > array[middle])
        return binarySearch(key, array,size, middle+ 1, max);
}
return false;
       
        
    }