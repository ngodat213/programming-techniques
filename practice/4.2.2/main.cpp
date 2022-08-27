#include<stdio.h>

int Fibonacci(int n){
    if(n == 1 || n == 2){
        return 1;
    }
    return Fibonacci(n-1) + Fibonacci(n-2);
}

int main(){
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("Fibonacci: %d", Fibonacci(n));
    return 0;
}
