#include <stdio.h>

int main(){
    char* p;
    char* s;
    int len = 0;
    s = (char*)malloc(sizeof(char)*80);

    printf("Enter a string : ");
    scanf("%s",s);

    p = s;

    while (*p)
    {
        p++;
        len++;
    }

    printf("the length of string %s = %d\n",s,len);
    return 0;
}
