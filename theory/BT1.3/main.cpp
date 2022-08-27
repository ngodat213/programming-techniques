#include <stdio.h>
#include <ctype.h>

int strLen(char c[]){
    int res = 0;
    while(c[res] != '\0'){
        res++;
    }
    if(res > 0) return res;
    return -1;
}
void UpperChar(char &c){
    if(c >= 'a' && c <= 'z') c-=32;
}

void LowerChar(char &c){
    if(c >= 'A' && c <= 'Z') c  +=32;
}

void ToLower(char c[]){
    for(int i = 0; i < strLen(c); ++i){
        LowerChar(c[i]);
    }
}

void Capitalize(char c[]){
    ToLower(c);
    UpperChar(c[0]);
    for(int i = 0; i < strLen(c); ++i){
        if(c[i] == ' ' && c[i+1] != ' '){
            UpperChar(c[i+1]);
            for(int j = i+2; j < strLen(c); ++j){
                if(c[j] != ' ') LowerChar(c[j]);
                else break;
            }
        }
    }
}


int main()
{
    int i = 30;
    char c[30];
    gets(c);
    Capitalize(c);
    for(int i = 0; i < strLen(c); ++i) printf("%c", c[i]);
    return 0;
}
