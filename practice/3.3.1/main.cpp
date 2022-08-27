#include<stdio.h>
#define MAX 10
typedef struct PS{
    int a, b;
};

void SetPS(PS *ps){
    printf("Nhap tu so: ");
    scanf("%d", &ps->a);
    printf("Nhap mau so: ");
    scanf("%d", &ps->b);
}

void ScanNum(int &n){
    printf("Nhap n, 0 < n <= 100: ");
    do{
        scanf("%d", &n);
        if(n <= 0 || n > 100){
            printf("Qua so luong quy dinh!\n");
        }
    }while(n <= 0 || n > 100);
}

void GetPS(PS *ps){
    printf("%d/%d\n", ps->a, ps->b);
}

void SetPS_Arr(PS *ps, int &n){
    ScanNum(n);
    for(int i = 0; i < n; ++i){
        SetPS((ps+i));
    }
}

void GetPS_Arr(PS *ps, int n){
    for(int i = 0; i < n; ++i){
        GetPS(ps+i);
    }
}

float GetFloatPS(PS *ps){
    return (1.0*ps->a)/ps->b;
}

void MaxPS_Arr(PS *ps, int n){
    int maxPS = 0;
    for(int i = 1; i < n; ++i){
        if(GetFloatPS((ps+maxPS)) < GetFloatPS((ps+i)))
            maxPS = i;
    }
    GetPS(ps+maxPS);
}

PS* SumPS(PS *ps1, PS *ps2){
    PS sum;
    sum.a = ps1->a * ps2->b + ps1->b * ps2->a;
    sum.b = ps1->b * ps2->b;
    PS *res = &sum;
    return res;
}

PS* SumPS_Arr(PS *ps, int n){
    PS *sum = ps;
    for(int i = 1; i < n; ++i){
        sum =  SumPS(sum, ps+i);
    }
    return sum;
}

int main(){
    int n;
    PS *ps = new PS[MAX];
    PS *ps1;
    //a
    printf("-=============A=============-\n");
    SetPS(ps1);
    //b
    printf("-=============B=============-\n");
    SetPS_Arr(ps, n);
    //c
    printf("-=============C=============-\n");    GetPS(ps1);
    //d
    printf("-=============D=============-\n");
    GetPS_Arr(ps, n);
    //e
    printf("-=============E=============-\n");
    printf("Max PS: ");
    MaxPS_Arr(ps, n);
    //f
    printf("-=============F=============-\n");
    printf("Tong cac phan so trong mang: ");
    GetPS(SumPS_Arr(ps, n));
    return 0;
}
