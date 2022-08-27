#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 100

using ll = long long;
typedef int MT2[MAX][MAX];

void ScanSizeArr(int &n){
    printf("Nhap n = row = column: ");
    scanf("%d", &n);
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
    printf("--> ");
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            printf("%2d ", a[i][j]);
        }
        if(i != n-1) printf("\n    ");
    }
}

void MainDiagonal(MT2 a, int n){
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        printf("%d ", a[cnt++][i]);
    }
}

void Diagonal(MT2 a, int n){
    int cnt = 4;
    for(int i = 0; i < n; ++i){
        printf("%d ", a[i][cnt--]);
    }
}

ll SumRowK(MT2 a, int n, int k){
    ll res = 0;
    for(int i = 0; i < n; ++i){
        res += a[i][k];
    }
    return res;
}

void SumRow(int sumRow[], MT2 a, int n){
    for(int i = 0; i < n; ++i){
        for(int  j = 0 ; j < n; j++){
            sumRow[j] += a[j][i];
        }
    }
}

void PrintSumRow(MT2 a, int n){
    int sumRow[n] = {0};
    SumRow(sumRow, a, n);
    for(int i = 0; i < n; ++i)
        printf("\nRow[%d]: %d", i+1, sumRow[i]);
}

ll MaxArr(int arr[], int len){
    ll res = arr[0];
    for(int i = 1; i < len; ++i){
        if(res < arr[i])
            res = arr[i];
    }
    return res;
}

void MaxSumRow(MT2 a, int n){
    int sumRow[n] = {0};
    SumRow(sumRow, a, n);
    int maxSum = MaxArr(sumRow, n); // Find max element in sumRow array
    for(int i = 0; i < n; ++i){
        if(maxSum == sumRow[i])
            printf("\nMaxRow[%d]: %d ", i+1, sumRow[i]);
    }
}

int main()
{
    MT2 a;
    int n;
    ScanSizeArr(n);
    RandomArray2(a, n);
    Print(a, n);
    PrintSumRow(a, n);
    MaxSumRow(a, n);
    return 0;
}
