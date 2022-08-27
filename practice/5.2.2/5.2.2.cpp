#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define PATH "D:\\test\\test.txt"
#define MAX 100

void SinhMaTran(int a[][MAX], int d, int c){
	srand((unsigned)time(0));
	for(int i = 0; i < d; ++i){
		for(int j =0; j < c; ++j){
			a[i][j] = rand() % 10;
		}
	}
}

void LuuFile(char path[], int a[][MAX], int d, int c){
	FILE *f = fopen(path, "w");
	if(f == NULL){
		printf("Khong tao duoc file\n");
	}
	fprintf(f, "%d %d\n", d, c);
	for(int i = 0; i < d; ++i){
		for(int j = 0; j < c; ++j){
			fprintf(f, "%d ", a[i][j]);
		}
		fprintf(f, "\n");
	}
	fclose(f);
}

void DocFile(char path[], int a[][MAX], int &d, int &c){
	FILE *f = fopen(path, "r");
	fscanf(f, "%d%d", &d, &c);
	for(int i = 0; i < d; ++i){
		for(int j = 0; j < c; ++j){
			fscanf(f, "%d", &a[i][j]);
		}
	}
}

void XuatMang(int a[][MAX], int d, int c){
	printf("%d %d\n", d, c);
	for(int i = 0; i < d; ++i){
		for(int j = 0; j < c; ++j){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int a[MAX][MAX], d = 10, c = 10;
	int b[MAX][MAX], x, y;
	SinhMaTran(a,d,c);
	LuuFile(PATH, a, d, c);
	DocFile(PATH, b, x, y);
	XuatMang(b,x,y);
	return 0;
}
