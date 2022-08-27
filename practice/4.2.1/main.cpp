#include <stdio.h>

void ScanArr(int a[], int n){
    if(n == 0)
        return;
    ScanArr(a, n-1);
    printf("a[%d]: ", n-1);
    scanf("%d", &a[n-1]);
}

void PrintArr(int a[], int n){
    if(n==0)
        return;
    PrintArr(a, n-1);
    printf("\na[%d]: %d", n-1, a[n-1]);
}

int SumArr(int a[], int n){
    if(n == 0)
        return 0;
    return SumArr(a, n-1) + a[n-1];
}

int SumEvenArr(int a[], int n){
    if(n == 0)
        return 0;
    if(a[n-1] % 2 == 0) return SumEvenArr(a, n-1) + a[n-1];
    else return SumEvenArr(a, n-1);
}

int CntPositive(int a[], int n){
    if(n == 0)
        return 0;
    if(a[n-1] > 0) return CntPositive(a, n-1) + 1;
    else return CntPositive(a, n-1);
}

int MaxArr(int a[], int n){
    if(n == 1)
        return a[0];
    if(a[n-1] > MaxArr(a, n-1))
        return a[n-1];
    else return MaxArr(a, n-1);
}

int MinArr(int a[], int n){
    if(n == 1)
        return a[0];
    if(a[n-1] < MaxArr(a, n-1))
        return a[n-1];
    else return MaxArr(a, n-1);
}

int LastEven(int a[], int n){
    if(n == 1){
        if(a[0] % 2 == 0) return a[0];
        else return -1;
    }
    if(a[n-1] % 2 == 0) return a[n-1];
    else return LastEven(a, n-1);
}

int FindFisrtX(int a[], int n, int x){
    if(n == 1){
        if(a[0] == x) return a[0];
        else return -1;
    }
    if(a[n-1] == x) return n-1;
    else return FindFisrtX(a, n-1, x);
}

int main()
{
    int a[100], n = 5;
    ScanArr(a,n);
    PrintArr(a, n);
    printf("\nTong cac phan tu trong mang: %d", SumArr(a, n));
    printf("\nTong cac phan tu chan trong mang: %d", SumEvenArr(a, n));
    printf("\nSo phan tu chan trong mang: %d", CntPositive(a, n));
    printf("\nPhan tu lon nhat trong mang: %d", MaxArr(a, n));
    printf("\nChan cuoi cung trong mang: %d", LastEven(a, n));
    printf("\nPhan tu X cuoi cung trong mang: %d", FindFisrtX(a, n, 5));
    return 0;
}