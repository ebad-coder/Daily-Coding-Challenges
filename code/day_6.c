/*
Given two strings, determine if they are anagrams of each other
(contain the same characters in any order).

Ignore casing and white space.
*/

#include <stdio.h>
#include "../lib/utils.h"

int is_anagram(char* str1, char* str2) {
    remove_whitespaces(str1);
    convert_to_lowercase(str1);

    remove_whitespaces(str2);
    convert_to_lowercase(str2);

    int sum1 = 0, sum2 = 0;

    for (int i = 0; str1[i] != '\0'; ++i) {
        sum1 += str1[i];
    }

    for (int i = 0; str2[i] != '\0'; ++i) {
        sum2 += str2[i];
    }

    return sum1 == sum2;
}

int main()
{
    char str1[] = "listen";
    char str2[] = "silent";
    printf("%d\n", is_anagram(str1, str2));
}