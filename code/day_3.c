/*
The Fibonacci sequence is a series of numbers where each number is the sum
of the two preceding ones. When starting with 0 and 1, the first 10 numbers in
the sequence are 0, 1, 1, 2, 3, 5, 8, 13, 21, 34.

Given an array containing the first two numbers of a Fibonacci sequence,
and an integer representing the length of the sequence, return an array containing
the sequence of the given length.

Your function should handle sequences of any length greater than or equal to zero.
If the length is zero, return an empty array.
Note that the starting numbers are part of the sequence.
*/

#include <stdio.h>
#include <stdlib.h>
#include "../lib/utils.h"

long* fibonacci_sequence(int* arr, int n)
{
    // return NULL meaning empty list
    if (n <= 0) return NULL;

    // create a new array for storing the sequence
    long* sequence = (long*)malloc(n * sizeof(long));
    if (sequence == NULL) return NULL;

    // copy the two elements of input array into result array
    sequence[0] = (long)arr[0];
    if (n > 1) sequence[1] = (long)arr[1];

    // loop till the nth term
    for (int i = 2; i < n; ++i) {
        // store new fibonacci number by adding pevious two numbers
        sequence[i] = sequence[i - 1] + sequence[i - 2];
    }

    // return the result array
    return sequence;
}

int main() {
    int arr[] = {0, 1};
    long* result = fibonacci_sequence(arr, 20);
    print_long_arr(result, 20); // [0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181]
    free(result);
    return 0;
}