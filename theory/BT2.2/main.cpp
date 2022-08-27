#include <stdio.h>
#include <math.h>

#define MIN_ARR 0
#define MAX_ARR 100

using ll = long long;

void ScanSize(int &row, int &column){
    printf("Nhap row, column: ");
    do{
        scanf("%d", &row);
        scanf("%d", &column);
    }while(row < MIN_ARR || column > MAX_ARR);
}

void ScanArr2(int **arr, int row, int column){
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            scanf("%d", (*(arr+i) + j));
        }
    }
}
void PrintArr2(int **arr, int row, int column){
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            printf("%d ", *(*(arr+i) + j));
        }
        printf("\n");
    }
}

ll SumArr2(int **arr, int row, int column){
    ll res = 0;
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            res += *(*(arr+i) + j);
        }
    }
    return res;
}

ll SumEvenArr2(int **arr, int row, int column){
    ll res = 0;
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            if(*(*(arr+i) + j) % 2 == 0){
                res += *(*(arr+i) + j);
            }
        }
    }
    return res;
}

ll SumOddArr2(int **arr, int row, int column){
    return SumArr2(arr,row,column) - SumEvenArr2(arr,row,column);
}

int _isPrime(int n){
    if(n < 2) return 0;
    for(int i = 2; i <= sqrt(n); ++i){
        if(n%i == 0) return 0;
    }
    return 1;
}

ll SumPrimeArr2(int **arr, int row, int column){
    ll res = 0;
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            if(_isPrime(*(*(arr+i) + j)) == 1){
                res += *(*(arr+i) + j);
            }
        }
    }
    return res;
}

int main()
{

    return 0;
}

