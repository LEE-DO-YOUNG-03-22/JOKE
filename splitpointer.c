#include <stdio.h>

int split_shap(char* src, char* dst);

int main(){
    int i = 0, i_num;
    char str[20] = "abcd#abcd###";
    char str_ss[20];

    i_num = split_shap(str, str_ss);
    for(i = i_num; i>=0 ; i--){
        printf("%c",str_ss[i]);
    }
}

int split_shap(char* src, char* dst){
    int i_num = 0;
    while (1)
    {
        if(*src == '\0' || *src == '#'){
            break;
        }
        *dst = *src;
        i_num++;
        src++;
        dst++;
    }
    *dst = '\0';
    
    return i_num;
}
