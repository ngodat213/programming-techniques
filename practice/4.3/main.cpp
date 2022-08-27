#include<stdio.h>

void Tower(int n, char A, char B, char C){
    if(n == 1)
        printf("%c -> %c\n", A, C);
    else{
        Tower(n-1, A, C, B);
        printf("%c -> %c\n", A, C);
        Tower(n-1, B, A, C);
    }
}

int main(){
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    Tower(n, 'A', 'B', 'C');
    return 0;
}
