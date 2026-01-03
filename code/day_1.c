/*
Given a string, determine whether the number of vowels in the first half of the string is equal
to the number of vowels in the second half.

The string can contain any characters.
The letters a, e, i, o, and u, in either uppercase or lowercase, are considered vowels.
If there's an odd number of characters in the string, ignore the center character.
*/

#include <stdio.h>
#include <string.h>
#include "../lib/utils.h"

int is_balanced(char* str)
{
    // calculate the length of the input string:
    int n = strlen(str);
    // track number of left side vowels
    int left_vowels = 0;
    // track number of right side vowels
    int right_vowels = 0;

    // loop till the half of the string
    for (int i = 0; i < n/2; ++i) {
        // check character from the first half
        if (is_vowel(str[i])) {
            ++left_vowels;
        }
        // check character from the second half
        if (is_vowel(str[n-1-i])) {
            ++right_vowels;
        }
    }

    // return true if both side vowels are equal, and false otherwise
    return right_vowels == left_vowels;
}

int main()
{
    // testing the function
    printf("%d\n", is_balanced("racecar")); // True
    printf("%d\n", is_balanced("Lorem Ipsum")); // True
    printf("%d\n", is_balanced("Kitty Ipsum")); // False
    printf("%d\n", is_balanced("string")); // False
    printf("%d\n", is_balanced(" ")); // True
    printf("%d\n", is_balanced("abcdefghijklmnopqrstuvwxyz")); // False
    printf("%d\n", is_balanced("123A#b!E&*456-o.U")); // True
}