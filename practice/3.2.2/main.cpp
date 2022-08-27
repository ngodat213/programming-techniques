#include<stdio.h>

void ScanSize(int &r, int &c){
    do{
		printf("Nhap gia tri m va n: ");
		scanf("%d%d", &r, &c);
	}while(r<=0 || c<=0 || r>=100 || c>=100);
}

void ScanArr(int **a, int r, int c){
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            printf("a[%d][%d]: ", i, j);
            scanf("%d", (*(a+i)+j));
        }
    }
}

void PrintArr(int **a, int r, int c){
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            printf("%d ", *(*(a+i)+j));
        }
        printf("\n");
    }
}

int SumArr(int **a, int r, int c){
    int res = 0;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            res += *(*(a+i)+j);
        }
    }
    return res;
}

void FreeArr(int **a, int r, int c){
    for(int i = 0; i < r; ++i){
        delete []a[i];
    }
    delete []a;
}

int main(){
    int r, c;
    ScanSize(r, c);
    int **a = new int*[r];
    for(int i = 0; i < r; ++i){
        a[i] = new int[c];
    }
    ScanArr(a, r, c);
    PrintArr(a, r, c);
    printf("Tong mang: %d\n", SumArr(a, r, c));
    FreeArr(a, r, c);
    return 0;
}
