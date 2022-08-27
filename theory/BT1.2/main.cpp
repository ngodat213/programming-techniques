#include <stdio.h>
#include <math.h>

void ScanArr(int a[], int x){
    int boolArr[100001][2] = {0};
    for(int i = 0; i < x; ++i){
        scanf("%d", &a[i]);
        if(a[i] >= 0){
            if(boolArr[a[i]][0] == 0 && a[i] >= 0) boolArr[a[i]][0] = 1;
            else{
                printf("-> Nhap Lai!\n");
                i--;
            }
        }else{
            if(boolArr[-1*a[i]][1] == 0 && a[i] < 0) boolArr[-1*a[i]][1] = 1;
            else{
                printf("-> Nhap Lai!\n");
                i--;
            }
        }
    }
}

void PrintArray(int a[], int x){
    printf("-->: ");
    for(int i = 0; i < x; ++i){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int IsScp(int x){
    int sqr = sqrt(x);
    if(sqr*sqr == x) return 1;
    return 0;
}

int PrintScpOdd(int a[], int x){
    for(int i = 0; i < x; ++i){
        if(i % 2 != 0 && IsScp(a[i]) == 1) printf("%d ", a[i]);
    }
    printf("\n");
}


int maxArray(int a[], int x){
    int maxI = 0;
    for(int i = 1; i < x; i++){
        if(a[i] > a[maxI]) maxI = i;
    }
    return a[maxI];
}

void PrintMax(int a[], int x){
    int tg = maxArray(a, x);
    for(int i = 0; i < x; ++i){
        if(a[i] == tg) printf("%d ", i);
    }
    printf("\n");
}

int FirstNegativeNum(int a[], int x){
    for(int i = 0; i < x; ++i){
        if(a[i] < 0) return i;
    }
    return -1;
}

int FirstPositiveNum(int a[], int x){
    for(int i = 0; i < x; ++i){
        if(a[i] > 0) return i;
    }
    return -1;
}

int MaxNegativeNum(int a[], int x){
    if(FirstNegativeNum(a, x) != -1){
        int Max = FirstNegativeNum(a,x);
        for(int i = FirstNegativeNum(a,x); i < x; ++i){
            if(a[i] > a[Max] && a[i] < 0) Max = i;
        }
        return Max;
    }
    return 1;
}

int MinPositiveNum(int a[], int x){
    if(FirstPositiveNum(a, x) != -1){
        int Min = FirstPositiveNum(a,x);
        for(int i = FirstPositiveNum(a,x); i < x; ++i){
            if(a[i] < a[Min] && a[i] > 0) Min = i;
        }
        return Min;
    }
    return -1;
}


int SumIEven(int a[], int x){
    int res = 0;
    for(int i = 0; i < x; ++i){
        if(i % 2 == 0) res+=a[i];
    }
    return res;
}

void Swap(int &x, int &y){
    int tg = x;
    x = y;
    y = tg;
}


void SelectionSortUp(int a[], int x, int st){
    for(int i = st; i < x-1; ++i){
        int minI = i;
        for(int j = i+1; j < x; ++j){
            if(a[j] < a[minI]) minI = j;
        }
        if(minI != i) Swap(a[minI], a[i]);
    }
}


int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    // a
    printf("a. Nhap mang: ");
    ScanArr (a, n);
    // b
    printf("b. Xuat mang: ");
    PrintArray(a, n);
    // c
    printf("c. So chinh phuong vi tri le: ");
    PrintScpOdd(a, n);
    // d
    printf("d. Vi tri gia tri lon nhat: ");
    PrintMax(a, n);
    // e
    printf("e. So am max: ");
    if(MaxNegativeNum(a, n) != -1)
        printf("%d, ", a[MaxNegativeNum(a,n)]);
    else printf("NO");

    printf("So duong min: ");
    if(MinPositiveNum(a, n) != -1)
        printf("%d\n", a[MinPositiveNum(a,n)]);
    else printf("NO\n");
    // f
    printf("f. Tong vi tri chan: %d\n", SumIEven(a, n));
    // g
    printf("g. Sap xep: ");
    SelectionSortUp(a, n, 0);
    PrintArray(a, n);
    return 0;
}
