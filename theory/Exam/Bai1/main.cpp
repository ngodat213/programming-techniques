#include<stdio.h>

void NhapSL(int *n){
    while(true){
        scanf("%d", n);
        if(*n > 0 && *n <= 100)
            break;
        NhapSL(n);
    }
}

void NhapMang(int *a, int n){
    if(n == 0) return;
    NhapMang(a, n-1);
    printf("a[%d]: ", n);
    scanf("%d", a+(n-1));
}

void XuatMang(int *a, int n){
    if(n == 0) return;
    XuatMang(a, n-1);
    printf("a[%d]: %d\n", n, *(a+(n-1)));
}

int KiemTraLeC1(int *a, int n){
    if(n == 0) return 1;
    if(*(a+(n-1)) % 2 != 0) return 0;
    return KiemTraLeC1(a, n-1);
}

// Kiem tra le cach 2
int KiemTraLeC2(int *a, int n ,bool b = 1){
    if(n == 0 && b == 1) return 1;
    else if(b == 0)return 0;
    if(*(a+(n-1)) % 2 != 0) return KiemTraLeC2(a, n-1, 0);
    else KiemTraLeC2(a, n-1, 1);
}

int main(){
    int n;
    NhapSL(&n);
    int *a = new int[n];
    NhapMang(a, n);
    XuatMang(a, n);
    printf(KiemTraLeC1(a, n) ? "Mang khong chua so le" : "Mang chua so le");
    return 0;
}