#include<stdio.h>
#include<math.h>

int USCLN(int a, int b){
    if(b == 0) return a;
    return USCLN(b, a%b);
}

int BSCNN(int a, int b)
{
    float t = a%b;
    if(t == 0) return a;
    return a * BSCNN(b, t) / t;
}

int main(){
    int a, b, i;
    printf("Nhap a, b: ");
    scanf("%d%d", &a, &b);
    printf("USCLN: %d\n", USCLN(a, b));
    printf("BSCNN: %d\n", BSCNN(a, b));
    return 0;
}
