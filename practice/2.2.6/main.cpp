#include <stdio.h>
#define MAX 100

typedef struct Date{
    int _date;
    int _morth;
    int _year;
};

typedef struct PostOffice{
    int ID;
    char SendName[100];
    char RepName[100];
    float Weight;
    Date DateSent;
    char Description[1000];
    float Ship;
    float Price;
};

void ScanNum(int &n){
    printf("Nhap so luong san phan: 0 < n <= 100: ");
    do{
        scanf("%d", &n);
        if(n <= 0 || n > 100){
            printf("Qua so luong quy dinh!\n");
        }
    }while(n <= 0 || n > 100);
}

void ScanDate(Date &date){
    printf("Ngay: ");
    scanf("%d", &date._date);
    printf("Thang: ");
    scanf("%d", &date._morth);
    printf("Nam: ");
    scanf("%d", &date._year);
}

void PrintDate(Date date){
    printf("%d/%d/%d\n", date._date, date._morth, date._year);
}

void ScanPostOffice(PostOffice &PO){
    printf("Ma buu kien: ");
    scanf("%d", &PO.ID);
    fflush(stdin); // Xoa bo nho dem
    printf("Ten nguoi gui: ");
    gets(PO.SendName);
    fflush(stdin);
    printf("Ten nguoi nhan: ");
    gets(PO.RepName);
    printf("Trong luong: ");
    scanf("%f", &PO.Weight);
    ScanDate(PO.DateSent);
    fflush(stdin);
    printf("Noi dung buu kien: ");
    gets(PO.Description);
    printf("Don gia gui: ");
    scanf("%f", &PO.Ship);
}

void PrintPostOffice(PostOffice PO){
    printf("--------------------------------------------\n\n");
    printf("Ma buu kien: %d\n", PO.ID);
    printf("Ten nguoi gui: %s\n", PO.SendName);
    printf("Ten nguoi nhan: %s\n", PO.RepName);
    printf("Trong luong: %f\n", PO.Weight);
    printf("Ngay gui: ");
    PrintDate(PO.DateSent);
    printf("Noi dung buu kien: %s\n", PO.Description);
    printf("Don gia gui: %f\n", PO.Ship);
    printf("--------------------------------------------\n\n");
}

void ScanArrayPO(PostOffice PO[], int &n){
    ScanNum(n);
    for(int i = 0; i < n; i++){
        printf("-============A[%d]============-\n", i);
        ScanPostOffice(PO[i]);
    }
}

void PrintArrayPO(PostOffice PO[], int n){
    for(int i = 0; i < n; i++){
        PrintPostOffice(PO[i]);
    }
}

void AddPO(PostOffice PO[], int &n){
    ++n;
    ScanPostOffice(PO[n-1]);
}

void _swapPO(PostOffice &PO1, PostOffice &PO2){
    PostOffice tg = PO1;
    PO1 = PO2;
    PO2 = tg;
}
// InterChangeSort
void SortPO_ID(PostOffice PO[], int n){
    for(int i = 0; i < n-1; ++i){
        for(int j = i + 1; j < n; ++j){
            if(PO[i].ID > PO[j].ID)
                _swapPO(PO[i], PO[j]);
        }
    }
}

void PricePO(PostOffice PO[], int n){
    for(int i = 0; i < n; ++i){
        PO[i].Price = PO[i].Ship * PO[i].Weight;
    }
}

int MaxWeightPO(PostOffice PO[], int n){
    int res = 0;
    for(int i = 1; i < n; ++i){
        if(PO[res].Weight < PO[i].Weight)
            res = i;
    }
    return res;
}

int CountMaxWeightPO(PostOffice PO[], int n){
    int Max = MaxWeightPO(PO, n);
    int cnt = 0;
    /* Do ham MaxWeight ket thuc la vi tri cuoi cung
    nen for se chay tu vi tri cuoi ve truoc */
    for(int i = Max; i >= 0; --i){
        if(PO[i].Weight == PO[Max].Weight)
            cnt++;
    }
    return cnt;
}

void SearchPO_Name(PostOffice PO[], int n, char index[]){
    for(int i = 0; i < n; ++i){
        if(PO[i].SendName == index)
            PrintPostOffice(PO[i]);
    }
}

void SearchPO_Date(PostOffice PO[], int n, Date date){
    for(int i = 0; i < n; i++){
        if(PO[i].DateSent._date == date._date &&
           PO[i].DateSent._morth == date._morth &&
           PO[i].DateSent._year == date._year
        ){
            PrintPostOffice(PO[i]);
        }
    }
}

int main()
{
    int n;
    Date date;
    date._date = 1;
    date._morth = 1;
    date._year = 1
    ;
    PostOffice DataPostOffice[MAX];
    // a
    printf("-============A============-\n\n");
    ScanArrayPO(DataPostOffice, n);
    printf("-============B============-\n\n");
    PrintArrayPO(DataPostOffice, n);
    printf("-============C============-\n\n");
    AddPO(DataPostOffice, n);
    PrintArrayPO(DataPostOffice, n);
    printf("-============D============-\n\n");
    SortPO_ID(DataPostOffice, n);
    PrintArrayPO(DataPostOffice, n);
    printf("-============E============-\n\n");
    PricePO(DataPostOffice, n);
    printf("-============F============-\n\n");
    int vtMax = MaxWeightPO(DataPostOffice, n);
    int cnt = CountMaxWeightPO(DataPostOffice, n);
    printf("Max: %d | Count: %d\n", DataPostOffice[vtMax], cnt);
    printf("-============G============-\n\n");
    SearchPO_Name(DataPostOffice, n, "1");
    printf("-============H============-\n\n");
    SearchPO_Date(DataPostOffice, n, date);
}
