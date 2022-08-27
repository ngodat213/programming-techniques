#include<stdio.h>
#include<stdlib.h>

void ScanNum(int &n){
    printf("Nhap so luong san phan: 0 < n <= 100: ");
    do{
        scanf("%d", &n);
        if(n <= 0 || n > 100){
            printf("Qua so luong quy dinh!\n");
        }
    }while(n <= 0 || n > 100);
}

void ScanArr(int *a, int n){
    for(int i = 0; i < n; ++i){
        scanf("%d", (a+i));
    }
}

void PrintArr(int *a, int n){
    for(int i = 0; i < n; ++i){
        printf("%d ", *(a+i));
    }
    printf("\n");
}

int SumArr(int *a, int n){
    int res = 0;
    for(int i = 0 ; i < n; ++i){
        res += *(a+i);
    }
    return res;
}

int main(){
    int n, *a = new int[100];
    ScanNum(n);
    ScanArr(a, n);
    PrintArr(a, n);
    printf("Tong mang: %d\n", SumArr(a,n));
    delete []a;
    return 0;
}
