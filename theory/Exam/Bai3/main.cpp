#include <stdio.h>

typedef struct CanBo{
    char ID[10];
    char Ten[50];
    int NamSinh;
    char MaPhong[4];
    long long Luong;
}CB;

void Nhap1CanBo(CB &a){
    fflush(stdin);
    printf("Ma can bo: ");
    gets(a.ID);
    fflush(stdin);
    printf("Ten can bo: ");
    gets(a.Ten);
    printf("Nam sinh: ");
    scanf("%d", &a.NamSinh);
    fflush(stdin);
    printf("Ma phong: ");
    gets(a.MaPhong);
    printf("Luong: ");
    scanf("%lld", &a.Luong);
}

void NhapNCanBo(CB a[], int n){
    for(int i = 0; i < n; ++i){
        Nhap1CanBo(a[i]);
    }
}

int DemCanBo(CB a[], int n){
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        if(a[i].Luong >= 10000000 && a[i].NamSinh < 1990) cnt++;
    }
    return cnt;
}

int main()
{
    int n;
    printf("Nhap N can bo: ");
    scanf("%d", &n);
    CB a[n];
    NhapNCanBo(a, n);
    printf("So can bo luong 10000000 va truoc nam 1990: %d\n", DemCanBo(a, n));

    return 0;
}
