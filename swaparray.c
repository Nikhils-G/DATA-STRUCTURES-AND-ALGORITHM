#include <stdio.h>

void swap(int *xp, int *yp) 
{ 
   int temp = *xp; 
   *xp = *yp; 
   *yp = temp; 
}

void selectionSort(int array[], int size) 
{ 
    int i, j, min_idx;

    // Loop to iterate on array 
    for (i = 0; i < size-1; i++) 
    { 
        // Here we try to find the min element in array 
        min_idx = i; 
        for (j = i+1; j < size; j++)
        {
            if (array[j] < array[min_idx]) 
              min_idx = j; 
        }
        // Here we interchange the min element with first one 
        swap(&array[min_idx], &array[i]); 
     } 
}

/* Display function to print values */
void display(int array[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++)
    { 
       printf("%d ",array[i]);
    }
     printf("\n"); 
}

// The main function to drive other functions 
int main() 
{ 
   int array[] = {50, 30, 10, 90, 80, 20, 40, 70}; 
   int size = sizeof(array)/sizeof(array[0]);

   selectionSort(array, size);
  
   display(array, size);

   return 0; 
}
