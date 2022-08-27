#include<stdio.h>
#include<string.h>
#define MAX 100

int main(){
    char s1[MAX], s2[MAX];
    //a
    printf("nhap chuoi 1: ");
    gets(s1);
    printf("nhap chuoi 2: ");
    gets(s2);
    //b
    printf("s1: %s\ns2: %s\n", s1, s2);
    //c
    printf("do dai s1: %d\n", strlen(s1));
    printf("do dai s2: %d\n", strlen(s2));
    //d
    int cmp = strcmp(s1,s2);
    printf("so sanh: ");
    if(cmp > 0){
        printf("s1 > s2\n");
    }else if(cmp < 0){
        printf("s1 < s2\n");
    }else{
        printf("s1 = s2\n");
    }
    //e
    strcat(s1, s2);
    printf("chuoi duoc noi: %s\n", s1);
    //f
    char *check = strstr(s1, s2);
    if(check != NULL){
        printf("s1 co xuat hien trong s2\n");
    }else{
        printf("s1 co ko xuat hien trong s2\n");
    }
    char *check1 = strstr(s2, s1);
    if(check1 != NULL){
        printf("s2 co xuat hien trong s1\n");
    }else{
        printf("s2 co ko xuat hien trong s1\n");
    }
    return 0;
}
