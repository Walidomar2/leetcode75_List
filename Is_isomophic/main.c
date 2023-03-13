#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isIsomophic(char *s,char *t);

int main()
{
    bool flag = false ;
    char s[]="egg";
    char t[]="add";

    flag = isIsomophic(&s,&t);

    printf("flag = %s",flag ? "true":"false");

    return 0;
}

bool isIsomophic(char *s,char *t)
{
    if (strlen(s) != strlen(t))
     {
        return false;
     }

int i=0;
char s_map[256]={0} , t_map[256]={0};

while(s[i])
{
    if((s_map[s[i]]==0) && (t_map[t[i]]==0))
    {
        s_map[s[i]]=t[i];
        t_map[t[i]]=s[i];
    }
    else if((s_map[s[i]]!=t[i]) || (t_map[t[i]]!=s[i]))
    {
        return false;
    }
    i++;

}
    return true;
}

