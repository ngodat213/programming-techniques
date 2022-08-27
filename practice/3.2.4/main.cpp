#include<stdio.h>
#include<string.h>

void *ChuanHoa(char s[]){
    int i = 0, n = strlen(s);
    while(i < n){
        if(s[i] >= 'a' && s[i] <= 'z')
            s[i] -= 32;
        i++;
        while(i < n && s[i] != 32){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                s[i] += 32;
            }
            i++;
        }
        while(i < n && s[i] == 32)
            i++;
    }
    return s;
}

int main(){
    char c[100] = "nGo vAn tIEn daT";
    printf("Sau da chuan hoa: %s", ChuanHoa(c));
    return 0;
}
