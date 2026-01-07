/*
Given an array of numbers and an integer target, find two unique numbers in the
array that add up to the target value. Return an array with the indices of those 
two numbers, or empty array if no two numbers sum up to the target.

The returned array should have the indices in ascending order.
*/

#include <stdio.h>
#include <stdlib.h>

int* find_target(int* arr, int n, int target)
{
    // loop through each element of array
    for (int i = 0; i < n; ++i) {
        // for each element, loop the array again for the rest of elements
        for (int j = i + 1; j < n; ++j) {
            // if two different elements add up to target
            if (arr[i] + arr[j] == target) {
                // then create an array to hold both indices
                int* result = malloc(2 * sizeof(int));
                result[0] = i;
                result[1] = j;
                // return the result array
                return result;
            }
        }
    }
    // if no indices found, then return NULL to indicate empty array
    return NULL;
}

int main()
{
    int arr[] = {1, 3, 5, 6, 7, 8};
    int* result = find_target(arr, 6, 15);
    
    if (result == NULL) {
        printf("Target Not Found..");
    }
    else {
        printf("%d, %d", result[0], result[1]);
        free(result);
    }

    return 0;
}