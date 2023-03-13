#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isSubsequence(char* s, char* t);

int main()
{
    bool flag = false;
    char s[]="abc";
    char t[]="ahbgdc";

    flag = isSubsequence(&s,&t);

    printf("flag = %s ",flag ? "true" : "false");       // A way to print a bool value on screen

    return 0;
}

bool isSubsequence(char* s, char* t){
    if(*s == '\0' && *t == '\0')
        return true;

    char* temp = t;

    for(temp = t; *temp != '\0'; temp++) {
        if(*s == *temp)
         s++;

        if(*(s) == '\0')    // If you reach to the end of the s string it indicate that it is a subsequence from t string
         return true;
    }

    return false;
}
