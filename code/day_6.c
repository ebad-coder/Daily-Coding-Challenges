/*
Given two strings, determine if they are anagrams of each other
(contain the same characters in any order).

Ignore casing and white space.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_anagram(const char* str1, const char* str2)
{
    // array to keep track of frequency of each alphabet.
    int count[26] = {0};
    // store length of input strings
    int n1 = strlen(str1);
    int n2 = strlen(str2);

    // loop through the first input string
    for (int i = 0; i < n1; ++i) {
        // if the current character is an alphabet
        if (isalpha(str1[i])) {
            // then increment the characters index in the array
            count[tolower(str1[i]) - 'a']++;
        }
    }

    // loop through the second input string
    for (int i = 0; i < n2; ++i) {
        // if the current character is an alphabet
        if (isalpha(str2[i])) {
            // then decrement the characters index in the array
            count[tolower(str2[i]) - 'a']--;
        }
    }

    // if both strings are anagrams, then each element of array should be 0.
    for (int i = 0; i < 26; ++i) {
        if (count[i] != 0) return 0;
    }

    // return true if the array test pass, meaning both strings are anagrams.
    return 1;
}

int main()
{
    char str1[] = "Hello world";
    char str2[] = "worLD, hello";
    printf("%d\n", is_anagram(str1, str2));
}