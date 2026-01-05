/*
Given a string, return a jumbled version of that string where each word is transformed
using the following constraints:

The first and last letters of the words remain in place
All letters between the first and last letter are sorted alphabetically.
The input strings will contain no punctuation, and will be entirely lowercase.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../lib/utils.h"

void jbelmu(char* str)
{
    int n = strlen(str);
    int in_word = 0;
    for (int i = 0; i < n; ++i) {
        int j = 0;
        if (isalpha(str[i])) {
            while (str[i++] != ' ') ++j; 
        }
        printf("%d\n", j);
    }
}

int main()
{
    jbelmu("Ebad is good boy");
}