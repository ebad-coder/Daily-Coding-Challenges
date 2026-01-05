/*
Given a string, remove all spaces from the string, insert two spaces between every 
character, convert all alphabetical letters to uppercase, and return the result.

Non-alphabetical characters should remain unchanged (except for spaces).
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../lib/utils.h"

char* space_jam(char* str)
{
    // store the length of the string
    int n = strlen(str);

    // logic to remove whitespaces from the string
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (str[i] != ' ') str[j++] = str[i];
    }
    str[j] = '\0';

    // convert the modified string to uppercase
    convert_to_uppercase(str);

    // store the updated length of the string
    n = strlen(str);

    // created a string to store the result
    char* result = malloc((n*3) * sizeof(char));
    // keep track of result string index
    int result_index = 0;

    // loop through the input string
    for (int i = 0; i < n; ++i) {
        // store the character in the result string
        result[result_index++] = str[i];
        // if the current character is not last, then add two spaces to result string
        if (i < n-1) {
            result[result_index++] = ' ';
            result[result_index++] = ' ';
        }
    }

    // terminate the result string
    result[result_index] = '\0';
    // return the result string
    return result;
}

int main()
{
    char str1[] = "  Hello w #@# orld  ";
    printf("%s\n", space_jam(str1));
    char str2[] = "freeCodeCamp";
    printf("%s\n", space_jam(str2));
    char str3[] = "   free   Code   Camp   ";
    printf("%s\n", space_jam(str3));
    char str4[] = "C@t$ & D0g$";
    printf("%s\n", space_jam(str4));
    char str5[] = "Ebad Ziad Adam";
    printf("%s\n", space_jam(str5));
}