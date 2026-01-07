/*
Given a positive integer up to 1,000, return the sum of all the integers squared from 1 up to the number.
*/

#include <stdio.h>

long sum_of_squares(int n)
{
    // use to store the sum
    int result = 0;

    // loop from 1 to n
    for (int i = 1; i <= n; ++i) {
        // add each number square to result
        result += (i * i);
    }

    // return the result
    return result;
}

int main()
{
    printf("%ld\n", sum_of_squares(5));
    printf("%ld\n", sum_of_squares(10));
    printf("%ld\n", sum_of_squares(25));
    printf("%ld\n", sum_of_squares(500));
    printf("%ld\n", sum_of_squares(1000));
}