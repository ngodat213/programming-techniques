#include <stdio.h>
#define MAX 10
void ScanRC(int &r, int &c){
    printf("Row: ");
    scanf("%d", &r);
    printf("Column: ");
    scanf("%d", &c);
}

void ScanArray2(int a[][MAX], int r, int c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf("%d", &a[i][j]);
        }
    }
}

void PrintArray2(int a[][MAX], int r, int c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            printf("%2d ", a[i][j]);
        }
        printf("\n");
    }
}

int SumArray2(int a[][MAX], int r, int c){
    int res = 0;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            res+=a[i][j];
        }
    }
    return res;
}

double AvarageArray2(int a[][MAX], int r, int c){
    return 1.0*SumArray2(a,r,c) / (r*c);
}

int AvarageArray2P(int a[][MAX], int r, int c){
    double res = 0;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            if(a[i][j] > 0)res+=a[i][j];
        }
    }
    return res/ (r*c);
}

void PrintColumn(int a[][MAX], int c, int index){
    for(int i = 0; i < c; ++i){
        printf("%d ", a[i][index]);
    }
}

void PrintRow(int a[][MAX], int r, int index){
    for(int i = 0; i < r; ++i){
        printf("%d ", a[index][i]);
    }
}

int MaxArray2(int a[][MAX], int r, int c){
    int res = a[0][0];
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            if(a[i][j] > res) res = a[i][j];
        }
    }
    return res;
}

int main()
{
    int r, c;
    ScanRC(r, c);
    int a[r][MAX];
    ScanArray2(a,r,c);
    PrintRow(a,c,1);
    return 0;
}
