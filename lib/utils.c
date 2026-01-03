#include "utils.h"

int is_vowel(char c)
{
    if (c >= 65 && c <= 90) c += 32;

    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}