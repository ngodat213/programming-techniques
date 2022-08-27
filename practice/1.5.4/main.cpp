#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 100

using ll = long long;
typedef int MT2[MAX][MAX];

void ScanSizeArr(int &r, int &c){
    printf("Nhap row, column: ");
    scanf("%d", &r);
    scanf("%d", &c);
}

void Scan(MT2 a, int r, int c){
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            scanf("%d", &a[i][j]);
        }
    }
}

void RandomArray2(MT2 a, int r, int c){
    srand((unsigned int)time(NULL));
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            int kq = rand() % 10;
            a[i][j] = kq;
        }
    }
}

void Print(MT2 a, int r, int c){
    printf("--> ");
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            printf("%3d ", a[i][j]);
        }
        if(i != r-1) printf("\n    ");
    }
}

void OperatorAddArr(MT2 a, MT2 b, int rA, int cA, int rB, int cB){
    MT2 res;
    if(rA == rB || cA == cB){
        for(int i = 0; i < rA; ++i){
            for(int j = 0; j < cA; ++j){
                res[i][j] = a[i][j] + b[i][j];
            }
        }
        Print(res, rA, cA);
    }else printf("Matrices must be of the same size!\n");
}

int RowMulColumn(MT2 a, MT2 b, int cA, int r, int c){
    int res = 0;
    for(int i = 0; i < cA; ++i){
        res += a[r][i] * b[i][c];
    }
    return res;
}

void OperatorMulArr(MT2 a, MT2 b, int rA, int cA, int rB, int cB){
    MT2 res = {0};
    if(cA == rB){
        for(int i = 0; i < rA; ++i){
            for(int j = 0; j < cB; ++j){
                res[i][j] = RowMulColumn(a,b,cA,i,j);
            }
        }
        Print(res, rA, cB);
    }else printf("Matrices must be of the same size!\n");
}

int main()
{
    MT2 a, b;
    int rA, cA, rB, cB;
    ScanSizeArr(rA, cA);
    ScanSizeArr(rB, cB);
    Scan(a,rA,cA);
    Scan(b,rB,cB);
    printf("\nArray A: \n");
    Print(a,rA,cA);
    printf("\nArray B: \n");
    Print(b,rB,cB);
    printf("\nMul A * B: %d\n", RowMulColumn(a,b,rA,0,1));
    OperatorMulArr(a,b,rA,cA,rB,cB);
    return 0;
}
