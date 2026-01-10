/*
Given a secret message string, and an integer representing the number of letters that were used to shift 
the message to encode it, return the decoded string.

A positive number means the message was shifted forward in the alphabet.
A negative number means the message was shifted backward in the alphabet.
Case matters, decoded characters should retain the case of their encoded counterparts.
Non-alphabetical characters should not get decoded.
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char* decode(char* message, int shift) {
    // length of input string
    int n = strlen(message);

    // allocate memory for decoded string
    char* result = malloc(n + 1);
    // return NULL on allocation failure
    if (result == NULL) return NULL;

    // normalize shift to range [0, 25]
    shift %= 26;

    // iterate over each character
    for (int i = 0; i < n; ++i) {
        // decode only alphabetic characters
        if (isalpha(message[i])) {
            // determine base ('A' or 'a') for case preservation
            char base = isupper(message[i]) ? 'A' : 'a';

            // compute 0–25 index of character
            int index = message[i] - base;

            // apply reverse shift with wrap-around
            index = (index - shift) % 26;
            if (index < 0) index += 26;

            // store decoded character
            result[i] = base + index;
        } else {
            // copy non-alphabetic characters unchanged
            result[i] = message[i];
        }
    }

    // null-terminate result
    result[n] = '\0';
    return result;
}


int main()
{
    printf("%s\n", decode("Xlmw mw e wigvix qiwweki.", 4));
    printf("%s\n", decode("Byffi Qilfx!", 20));
    printf("%s\n", decode("Zqd xnt njzx?", -1));
    printf("%s\n", decode("oannLxmnLjvy", 9));
    return 0;
}