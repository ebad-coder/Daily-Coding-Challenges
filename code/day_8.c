/*
Given an integer from zero to 20, return the factorial of that number. The factorial 
of a number is the product of all the numbers between 1 and the given number.

The factorial of zero is 1.
*/

#include <stdio.h>

long long factorial(int n)
{
    // if n is lesser than or equal to 1, then its factorial would be 1
    if (n <= 1) return 1;
    // else the factorial is n times factorial of n-1. Example: 5! = 5 x 4!.
    return n * factorial(n - 1);
}

int main()
{
    printf("%lld\n", factorial(10));
    printf("%lld\n", factorial(5));
    printf("%lld\n", factorial(7));
    printf("%lld\n", factorial(4));
}