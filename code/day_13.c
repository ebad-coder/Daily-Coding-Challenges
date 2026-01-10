/*
Given an integer, determine if that number is a prime number or a negative prime number.

A prime number is a positive integer greater than 1 that is only divisible by 1 and itself.
A negative prime number is the negative version of a positive prime number.
1 and 0 are not considered prime numbers.
*/

#include <stdio.h>

int is_unnatural_prime(int n)
{
    // if n is negative, then make it positive
    if (n < 0) n = -n;
    // if n is lesser than 2, then it is not prime
    if (n < 2) return 0;
    // loop from 2 to sqrt(n)
    for (int i = 2; i*i <= n; ++i) {
        // if n is divisible by any number between 2 and sqrt(n), then it is not prime
        if (n % i == 0) return 0;
    }
    // return true if the loop ran successfully.
    return 1;
}

int main()
{
    printf("%d\n", is_unnatural_prime(1));
    printf("%d\n", is_unnatural_prime(-1));
    printf("%d\n", is_unnatural_prime(19));
    printf("%d\n", is_unnatural_prime(-23));
    printf("%d\n", is_unnatural_prime(0));
    printf("%d\n", is_unnatural_prime(97));
    printf("%d\n", is_unnatural_prime(-61));
    printf("%d\n", is_unnatural_prime(99));
    printf("%d\n", is_unnatural_prime(-44));
}