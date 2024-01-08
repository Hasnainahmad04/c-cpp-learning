#include <stdio.h>
#include <string.h>

int main()
{
    // Declare a Char Array for a string
    char str[] = "String in C";

    // char str2[];
    // str2 = "hii";
    // it will throw an error
    // printf("%s", str);

    char userStr[5];
    printf("Enter Any String: ");
    // used to get string input from user
    gets(userStr);
    printf("You Entered: %s", userStr);
    return 0;
}