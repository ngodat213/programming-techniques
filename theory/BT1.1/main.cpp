#include <stdio.h>

//a
void ScanNum(int &n){
    do{
        printf("Nhap n: ");
        scanf("%d", &n);
    }while(n < 0 && n > 101);
}

void scanArray(int a[], int x){
    for(int i = 0; i < x; ++i){
        scanf("%d", &a[i]);
    }
}
//b
void printArray(int a[], int x){
    printf("-->: ");
    for(int i = 0; i < x; ++i){
        printf("%d ", a[i]);
    }
    printf("\n");
}
//c
int fPositiveNum(int a[], int x){
    for(int i = 0; i < x; ++i){
        if(a[i] > 0) return i;
    }
    return -1;
}
//d
int lPositiveNum(int a[], int x){
    for(int i = x-1; i >= 0; --i){
        if(a[i] > 0) return i;
    }
    return -1;
}
//e
int maxArray(int a[], int x){
    int maxI = 0;
    for(int i = 1; i < x; i++){
        if(a[i] > a[maxI]) maxI = i;
    }
    return a[maxI];
}
//f
int cntMax(int a[], int x){
    int maxA = maxArray(a, x), cnt = 0;
    for(int i = 0; i < x; ++i){
        if(a[i] == maxA) ++cnt;
    }
    return cnt;
}
//g
int MaxIArray(int a[], int x){
    int maxN = maxArray(a, x);
    for(int i = 0; i < x; ++i){
        if(maxN == a[i]) return i;
    }
}
//h
void InsertArray(int a[], int &x, int st, int n){
    for(int i = x-1; i >= st-1; --i){
        a[i+1] = a[i];
    }
    a[st] = n;
    ++x;
}
//j
void DeleteArray(int a[], int &x, int vt){
    for(int i = vt; i < x; i++){
        a[i] = a[i+1];
    }
    --x;
}
//l
int checkOdd(int a[], int x){
    for(int i = 0; i < x; ++i){
        if(a[i] % 2 != 0) return 1;
    }
    return 0;
}

int main()
{
    int n, tg, vt;
    printf("a. ");
    ScanNum(n);
    int a[n];
    printf("Nhap mang: ");
    scanArray(a, n);
    printf("b. Xuat mang: ");
    printArray(a, n);
    printf("c. So duong dau tien: %d\n", fPositiveNum(a, n));
    printf("d. So duong cuoi cung: %d\n", lPositiveNum(a, n));
    printf("e. Gia tri lon nhat: %d\n", maxArray(a, n));
    printf("f. So phan tu lon nhat: %d\n", cntMax(a, n));
    printf("g: Vi tri cac phan tu max: %d\n", MaxIArray(a,n));
    printf("h: Nhap phan tu can them vao: ");
    scanf("%d", &tg);
    InsertArray(a, n, 0, tg);
    printArray(a, n);
    printf("i: Nhap phan tu: ");
    scanf("%d", &tg);
    printf("Vi tri: ");
    scanf("%d", &vt);
    InsertArray(a, n, vt, tg);
    printArray(a, n);
    printf("j: Xoa pha tu dau tien: ");
    DeleteArray(a, n, 0);
    printArray(a, n);
    printf("k: Nhap vi tri: ");
    vt = 0;
    while(vt<1 || vt>n){
        scanf("%d", &vt);
    }
    DeleteArray(a, n, vt);
    printArray(a, n);
    if(checkOdd(a, n) == 1) printf("l: Co phan tu le trong mang\n");
    else printf("l: Khong co phan tu le trong mang\n");
    return 0;
}
