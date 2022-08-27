#include <stdio.h>
#include <string.h>
#include <math.h>
// Nhap N
void ScanN(int n){
    printf("Nhap N: ");
    while(n < 1 || n > 99) scanf("%d", &n);
}
// Nhap mang
void ScanArr(int *a, int n){
    for(int i = 0; i < n; ++i) scanf("%d", a+i);
}
// Xuat mang
void PrintArr(int *a, int n){
    for(int i = 0; i < n; ++i) printf("%d ", *(a+i));
    printf("\n");
}
// Tong cac phan tu trong mang
int SumArr(int *a, int n){
    int res = 0;
    for(int i = 0; i < n; ++i) res += *(a+i);
    return res;
}
// Tong cac phan tu so chan trong mang
int SumArrEven(int *a, int n){
    int res = 0;
    for(int i = 0; i < n; ++i)
        if(*(a+i) % 2 == 0) res += *(a+i);
    return res;
}
// Tong cac phan tu so le trong mang
int SumArrOdd(int *a, int n){
    int res = 0;
    for(int i = 0; i < n; ++i)
        if(*(a+i) % 2 != 0) res += *(a+i);
    return res;
}
// Kiem tra so nguyen to
int isPrime(int n){
    if(n < 2) return 0;
    for(int i = 2; i <= sqrt(n); ++i){
        if(n % i == 0) return 0;
    }
    return 1;
}
// Tong cac so nguyen to torng mang
int SumArrPrime(int *a, int n){
    int res = 0;
    for(int i = 0; i < n; ++i)
        if(isPrime(*(a+i)) == 1) res += *(a+i);
    return res;
}
// So chan dau tien trong mang
int FirstEven(int *a, int n){
    for(int i = 0; i < n; ++i)
        if(*(a+i) % 2 == 0) return i;
}
// So le dau tien trong mang
int FirstOdd(int *a, int n){
    for(int i = 0; i < n; ++i)
        if(*(a+i) % 2 != 0) return i;
}
// So nguyen to dau tien torng mang
int FirstPrime(int *a, int n){
    for(int i = 0; i < n; ++i)
        if(isPrime(*(a+i)) == 1) return i;
}
// So chan cuoi cung
int LastEven(int *a, int n){
    for(int i = n-1; i >= 0; --i)
        if(*(a+i) % 2 == 0) return i;
}
// So le cuoi cung
int LastOdd(int *a, int n){
    for(int i = n-1; i >= 0; --i)
        if(*(a+i) % 2 != 0) return i;
}
// Kiem tra so chinh phuong
int isSquareNum(int n){
    int index = sqrt(n);
    if(index * index  == n) return 1;
    return 0;
}
// So chinh phuong cuoi cung trong mang
int LastSquareNum(int *a, int n){
    for(int i = n-1; i >= 0; --i)
        if(isSquareNum(*(a+i)) == 1) return *(a+i);
}
// So lon nhat trong mang
int MaxArr(int *a, int n){
    int res = *a+0;
    for(int i = 1; i < n; ++i)
        if(res < *a+i) res = *a+i;
    return res;
}
// Dem so chan trong mang
int CountEven(int *a, int n){
    int res = 0;
    for(int i = 0; i < n; ++i)
        if(*a+i % 2 == 0) res++;
    return res;
}
// Dem so lon nhat trong mang
int CountMax(int *a, int n){
    int res = 0;
    for(int i = 0; i < n; ++i)
        if(*a+i == MaxArr(a,n)) res++;
    return res;
}
// Vi tri lon nhat dau tien trong mang
int PrintFirstMax(int *a, int n){
    for(int i = 0; i < n; ++i)
        if(*a+i == MaxArr(a,n)) return i;
}
// Them 1 phan tu vao dau mang
void InsertFirstArr(int *a, int &n, int index){
    for(int i = n; i > 0; --i){
        a[i] = a[i-1];
    }
    a[0] = index;
    ++n;
}
// Them 1 phan tu vao cuoi mang
void InsertLastArr(int *a, int &n, int index){
    *(a+n) = index;
    ++n;
}
// Them mot phan tu vao vi tri do nguoi nhap
void InsertArr(int *a, int &n, int index, int st){
    for(int i = n; i >= st; --i){
        a[i] = a[i-1];
    }
    a[st] = index;
    ++n;
}
// Xoa phan tu chan dau tien
void DeleteFisrtEven(int *a, int &n){
    for(int i = FirstEven(a,n); i < n; ++i){
        a[i] = a[i+1];
    }
    --n;
}
// Xoa tat ca phan tu lon nhat
void DeleteAllMax(int *a, int &n){
    int maxArr = MaxArr(a,n);
    for(int i = 0; i < n; ++i){
        if(*(a+i) == maxArr){
            for(int j = i; j < n; ++j){
                a[j] = a[j+1];
            }
            --i;
            --n;
        }
    }
}
void _swap(int &a, int &b){
    int tg = a;
    a = b;
    b = tg;
}
// Sap xep mang: Interchange Sort
void InterchangeSort(int *a, int n){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(a[i] > a[j]) _swap(a[i], a[j]);
        }
    }
}

int main()
{

    int *a, n = 5;
    printf("N: ");
    scanf("%d", &n);
    a = new int[100];
    ScanArr(a,n);
    interchangeSort(a, n);
    PrintArr(a,n);
    return 0;
}
