/*
Given an integer between 1 and 10,000, return a count of how many numbers from 1 up to 
that integer whose square contains at least one digit 3.
*/

#include <stdio.h>

int squares_with_three(int n)
{
    // keep track of numbers whose square has digit 3
    int count = 0;
    // loop from 1 to n
    for (int i = 1; i <= n; ++i) {
        // calculate square of each number
        long long square = (long long)i * i;
        // loop until the square is not 0
        while (square) {
            // get the last digit of the square
            int digit = square % 10;
            // check if the digit is 3
            if (digit == 3) {
                // then increment the counter and break from the inner loop
                ++count;
                break;
            }
            // divide the square by 10 for next iteration
            square /= 10;
        }
    }

    // return the result
    return count;
}

int main()
{
    printf("%d\n", squares_with_three(1));
    printf("%d\n", squares_with_three(10));
    printf("%d\n", squares_with_three(100));
    printf("%d\n", squares_with_three(1000));
    printf("%d\n", squares_with_three(10000));
}