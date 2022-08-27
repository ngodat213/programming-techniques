#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 50
#define duongdan "D:\\test\\test.txt"

typedef struct hanghoa
{
	char ma[5];
	int sl;
	float dg; // don gia
	float st;
}HH;
//-------------------------------------------
void Nhap1HH(HH &h)
{
	printf("Nhap ma: "); scanf("%s", &h.ma);
	printf("So luong: "); scanf("%d", &h.sl);
	printf("Don gia: "); scanf("%f", &h.dg);
	h.st = h.sl*h.dg;
}
//-------------------------------------------
void Xuat1HH(HH h)
{
	printf("%s\t%4d\t%8.2f\t%8.2f\n", h.ma, h.sl, h.dg, h.st);
}
//-------------------------------------------
void NhapDSHH(HH a[], int &n)
{
	printf("Nhap sl loai HH: "); scanf("%d", &n);
	for( int i=0;i<n;i++)
		Nhap1HH(a[i]);
}
//-------------------------------------------
void XuatDSHH(HH a[], int n)
{
	for(int i=0; i<n; i++)
		Xuat1HH(a[i]);
}
//-------------------------------------------
void Luu1HHVaoFile(HH h, FILE *f)
{
	fprintf(f,"%s\t%4d\t%8.2f\t%8.2f\n", h.ma, h.sl, h.dg, h.st);
}
//-------------------------------------------
void LuuDSHHVaoFile(HH a[], int &n)
{
	FILE *f = fopen(duongdan, "wt");
	if(f==NULL) 
	{
		printf("\nKhong tao duoc file.");
	}
	fprintf(f, "%d\n", n);
	for(int i=0; i<n; i++)
	{
		fprintf(f,"%s %d %f %d\n", a[i].ma, a[i].sl, a[i].dg, a[i].st);
	}	
}
//-------------------------------------------
void DocDSHHTuFile(HH a[], int &n)
{
	FILE *f = fopen(duongdan, "rt");
	if(f==NULL) 
	{
		printf("\nKhong tao duoc file.");
		getch();
		exit(0);
	}
	fscanf(f, "%d", &n);
	for(int i=0; i<n; i++)
	{
		fscanf(f,"%s", &a[i].ma);
		fscanf(f,"%d", &a[i].sl);
		fscanf(f,"%f", &a[i].dg);
		fscanf(f,"%f", &a[i].st);
		
	}	
}

//==========================================
int main()
{
	HH a[MAX];
	int n;
	NhapDSHH(a, n);
	XuatDSHH(a, n);
	LuuDSHHVaoFile(a,n);
	HH b[MAX];
	int m;
	DocDSHHTuFile(b, m);
}
