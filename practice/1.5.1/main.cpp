#include <stdio.h>
#define maxN 100
typedef int MT2[maxN][maxN];

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

void Print(MT2 a, int r, int c){
    printf("--> ");
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            printf("%d ", a[i][j]);
        }
        if(i != r-1) printf("\n    ");
    }
}

int SumArr2(MT2 a, int r, int c){
    int res = 0;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            res+=a[i][j];
        }
    }
    return res;
}

double AverageArr2(MT2 a, int r, int c){
    return 1.0*SumArr2(a, r, c) / (r*c);
}

double AveragePositiveArr2(MT2 a, int r, int c){
    int sum = 0, cnt = 0;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            if(a[i][j] > 0){
                sum+=a[i][j];
                ++cnt;
            }
        }
    }
    return 1.0*sum/cnt;
}

void PrintRow(MT2 a, int r, int c){
    int k;
    scanf("%d", &k);
    printf("--> ");
    for(int i = 0; i < c; i++){
        printf("%d ", a[k][i]);
    }
    printf("\n");
}

void PrintColumn(MT2 a, int r, int c){
    int k;
    scanf("%d", &k);
    printf("--> ");
    for(int i = 0; i < r; i++){
        printf("%d ", a[i][k]);
    }
    printf("\n");
}

int MaxArray2(MT2 a, int r, int c){
    int res = a[0][0];
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            if(a[i][j] > res) res = a[i][j];
        }
    }
    return res;
}


int main(){
    MT2 a;
    int r, c;
    ScanSizeArr(r, c);
    printf("a. Nhap ma tran: ");
    Scan(a, r, c);
    printf("b. Xuat ma tran: \n");
    Print(a, r, c);
    printf("\nc. Tong ma tran: %d\n", SumArr2(a,r,c));
    printf("d. Trung binh cong ma tran: %.2lf\n", AverageArr2(a,r,c));
    printf("e. Trung binh cong cac phan tu duong: %.2lf\n", AveragePositiveArr2(a,r,c));
    printf("f. Nhap dong k: ");
    PrintRow(a, r, c);
    printf("g. Nhap cot k: ");
    PrintColumn(a, r, c);
    printf("h. Phan tu max: %d", MaxArray2(a,r,c));
    return 0;
}
