#include "utils.h"
#include <stdio.h>
#include <ctype.h>

int is_vowel(char c)
{
    if (c >= 65 && c <= 90) c += 32;

    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void print_long_arr(long* arr, int n)
{
    if (arr == NULL || n == 0) {
        printf("[]\n");
        return;
    }
    printf("[");
    for (int i = 0; i < n; ++i) {
        printf("%ld", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

void convert_to_uppercase(char* str)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        str[i] = toupper(str[i]);
    }
}

void convert_to_lowercase(char* str)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        str[i] = tolower(str[i]);
    }
}

void remove_whitespaces(char* str)
{
    int j = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] != ' ') str[j++] = str[i];
    }
    str[j] = '\0';
}