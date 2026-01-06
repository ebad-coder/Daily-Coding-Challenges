/*
Given a string, return a jumbled version of that string where each word is transformed
using the following constraints:

The first and last letters of the words remain in place
All letters between the first and last letter are sorted alphabetically.
The input strings will contain no punctuation, and will be entirely lowercase.
*/

#include <stdio.h>
#include <string.h>

// bubble-sort algorithm to sort characters in a given string
void bubble_sort(char* str, int start_index, int end_index)
{
    int length = end_index - start_index;
    for (int i = 0; i < length - 1; ++i) {
        int swapped = 0;
        for (int j = start_index; j < end_index - i - 1; ++j) {
            if (str[j] > str[j+1]) {
                char temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

char* jbelmu(char* str)
{
    // track the starting index of a word in the string
    int start_index = 0;
    // track the ending index of a word in the sring
    int end_index = 0;

    while (1) {
        // if we reach a whitespace or end of the string
        if (str[end_index] == ' ' || str[end_index] == '\0') {
            // then sort the middle of the word
            bubble_sort(str, start_index+1, end_index-1);
            // update the start index for new word
            start_index = end_index + 1;
        }
        // if we reach the end of string, then break of out of infinite loop
        if (str[end_index] == '\0') break;
        // increment ending index of a word in each iteration
        ++end_index;
    }
    
    // return the modified string
    return str;
}

int main()
{
    char str1[] = "hello world";
    printf("%s\n", jbelmu(str1)); // hello wlord
    char str2[] = "i love jumbled text";
    printf("%s\n", jbelmu(str2)); // i love jbelmud text
    char str3[] = "freecodecamp is my favorite place to learn to code";
    printf("%s\n", jbelmu(str3)); // faccdeeemorp is my faiortve pacle to laern to cdoe
    char str4[] = "the quick brown fox jumps over the lazy dog";
    printf("%s\n", jbelmu(str4)); // the qciuk borwn fox jmpus oevr the lazy dog
    char str5[] = "ebad ziad adam";
    printf("%s\n", jbelmu(str5)); // eabd zaid aadm
}