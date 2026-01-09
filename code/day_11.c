/*
Given a number of miles ran, and a time in "MM:SS" (minutes:seconds) it took to run those miles, 
return a string for the average time it took to run each mile in the format "MM:SS".

Add leading zeros when needed.
*/

#include <stdio.h>
#include <stdlib.h>

char* mile_pace(float miles, char* duration)
{
    int seconds = 0;
    seconds = seconds + ((duration[0] - '0') * 600);
    seconds = seconds + ((duration[1] - '0') * 60);
    seconds = seconds + ((duration[3] - '0') * 10);
    seconds = seconds + ((duration[4] - '0'));
    int average = seconds / miles;
    char* result = malloc(6);
    result[0] = (average / 600) + '0';
    average = average % 600;
    result[1] = (average / 60) + '0';
    average = average % 60;
    result[2] = ':';
    result[3] = (average / 10) + '0';
    average = average % 10;
    result[4] = average + '0';
    result[5] = '\0';
    return result;
}

int main()
{
    printf("%s\n", mile_pace(3, "24:00"));
    printf("%s\n", mile_pace(1, "06:45"));
    printf("%s\n", mile_pace(2, "07:00"));
    printf("%s\n", mile_pace(26.4, "45:12"));
}