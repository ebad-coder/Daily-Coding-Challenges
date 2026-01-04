/*
Given a string representing a number, and an integer base from 2 to 36,
determine whether the number is valid in that base.

The string may contain integers, and uppercase or lowercase characters.
The check should be case-insensitive.
The base can be any number 2-36.
A number is valid if every character is a valid digit in the given base.
Example of valid digits for bases:
Base 2: 0-1
Base 8: 0-7
Base 10: 0-9
Base 16: 0-9 and A-F
Base 36: 0-9 and A-Z
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int is_valid_number(char* num, int base)
{
    // variable to store the size of the string
    int n = strlen(num);
    
    for (int i = 0; i < n; ++i) {
        // variable to store the numeric value of current character
        int value;

        // calculate the numeric value of character if it is a digit
        if (isdigit(num[i])) {
            value = num[i] - '0';
        }
        // calculate the numeric value of character if it is an alphabet
        else if (isalpha(num[i])) {
            value = tolower(num[i]) - 'a' + 10;
        } 
        // the current character is a symbol, so return false
        else {
            return 0;
        }

        // the value should be lesser than the base, to be valid
        if (value >= base) {
            return 0;
        }
    }

    // return true if all the test passes.
    return 1;
}

int main()
{
    printf("%d\n", is_valid_number("10101", 2)); // true
    printf("%d\n", is_valid_number("10201", 2)); // false
    printf("%d\n", is_valid_number("76543210", 8)); // true
    printf("%d\n", is_valid_number("9876543210", 8)); // false
    printf("%d\n", is_valid_number("9876543210", 10)); // true
    printf("%d\n", is_valid_number("ABC", 10)); // false
    printf("%d\n", is_valid_number("ABC", 16)); // true
    printf("%d\n", is_valid_number("Z", 36)); // true
    printf("%d\n", is_valid_number("ABC", 20)); // true
    printf("%d\n", is_valid_number("4B4BA9", 16)); // true
    printf("%d\n", is_valid_number("5G3F8F", 16)); // false
    printf("%d\n", is_valid_number("5G3F8F", 17)); // true
    printf("%d\n", is_valid_number("abc", 10)); // false
    printf("%d\n", is_valid_number("abc", 16)); // true
    printf("%d\n", is_valid_number("AbC", 16)); // true
    printf("%d\n", is_valid_number("z", 36)); // true
}