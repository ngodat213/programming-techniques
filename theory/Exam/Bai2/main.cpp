#include<stdio.h>
#include<math.h>
#define MAX 100

void NhapSL(int &m, int &n){
    scanf("%d%d", &m, &n);
}

void NhapMaTran(int a[][MAX], int m, int n){
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            printf("Nhap a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("\n");
}

void XuatMaTran(int a[][MAX], int m, int n){
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
}

int TongDongK(int a[][MAX], int m, int n, int pos){
    int s = 0;
    for(int i = 0; i < n; ++i){
        s += a[pos][i];
    }
    return s;
}

int PhanTuLonNhat(int a[][MAX], int m, int n){
    int res = a[0][0];
    for(int i = 0; i < m; ++i){
        for(int  j = 0; j < n; ++j){
            if(a[i][j] > m)
                res = a[i][j];
        }
    }
    return res;
}

bool isPrime(int n){
    if(n < 2) return 0;
    for(int i = 2; i <= sqrt(n); ++i){
        if(n%i ==0) return 0;
    }
    return 1;
}

int SoNguyenToCuoiCung(int a[][MAX], int m, int n){
    int p = 0;
    for(int i = m-1; i >= 0; --i){
        for(int j = n-1; j >= 0; --j){
            if(isPrime(a[i][j]) == 1) return a[i][j];
        }
    }
    return -1;
}

int main()
{
    int m, n, a[MAX][MAX], pos;
    NhapSL(m, n);
    NhapMaTran(a, m, n);
    XuatMaTran(a, m, n);
    printf("Nhap dong k : ");
    scanf("%d", &pos);
    printf("Tong dong k : %d\n", TongDongK(a, m, n, pos));
    printf("Phan tu lon nhat : %d\n", PhanTuLonNhat(a, m, n));
    printf("So nguyen to cuoi cung : %d\n", SoNguyenToCuoiCung(a, m, n));
    return 0;
}
