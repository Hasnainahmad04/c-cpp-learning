#include <stdio.h>
#include <string.h>

int main()
{
    // Declare a Char Array for a string
    char str[] = "String in C";
    // strlen used to get the length of a string
    int len = strlen(str);
    printf("The Length of String is: %d \n", len);

    char str1[] = "Hello ";
    char str2[] = "Nain!";
    // strcat: It will concatinate str1 and str2, and store the result in str1
    strcat(str1, str2);
    printf("%s \n", str1);

    char cpy1[20] = "Hello World!";
    char cpy2[20];

    // Copy cpy1 to cpy2
    strcpy(cpy2, cpy1);
    printf("%s \n", cpy2);

    return 0;
}