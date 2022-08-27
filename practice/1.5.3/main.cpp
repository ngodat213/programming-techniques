#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 100

using ll = long long;
typedef int MT2[MAX][MAX];

void ScanArr(MT2 a, int n){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            scanf("%d", &a[i][j]);
        }
    }
}

void RandomArray2(MT2 a, int n){
    srand((unsigned int)time(NULL));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            int kq = rand() %100;
            a[i][j] = kq;
        }
    }
}

void Print(MT2 a, int n){
    printf("\n--> ");
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            printf("%2d ", a[i][j]);
        }
        if(i != n-1) printf("\n    ");
    }
}


void OutlineArr(MT2 a, int n){
    printf("\n");
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(j == 0 || j == n-1){
                printf("%2d ", a[i][j]);
            }else if(i == 0 || i == n-1){
                printf("%2d ", a[i][j]);
            }else printf("   ");
        }
        printf("\n");
    }
}

ll SumOutlineArr(MT2 a, int n){
    ll res = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(j == 0 || j == n-1){
                res += a[i][j];
            }else if(i == 0 || i == n-1){
                res += a[i][j];;
            }
        }
    }
    return res;
}

int CheckSymmetrical(MT2 a, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; ++j){
            if(a[i][j] != a[j][i]) return 0;
        }
    }
    return 1;
}

int main()
{
    MT2 a;
    int n;
    scanf("%d", &n);
    ScanArr(a, n);
    Print(a,n);
    OutlineArr(a,n);
    printf("Check Symmetrical: %lld", CheckSymmetrical(a,n));
    return 0;
}
