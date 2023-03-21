#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int longestPalindrome(char * s);
int main()
{
    char *str = "abccccdd";
    int result =0;

    result = longestPalindrome(str);

    printf("%i" , result);

    return 0;
}

int longestPalindrome(char * s)
{
    int mapArr[58]={0};

    for (int i = 0; i <strlen(s); ++i) {
        mapArr[s[i] - 'A']++;
    }

    int result = 0;

    for (int i = 0; i < 58; ++i) {
        result += (mapArr[i] / 2)*2;
    }
    if (result < strlen(s) ) {
        result++;
    }
    return result;
}
