#include<stdio.h>
#include<string.h>
#define MAX 100

typedef struct BookStore{
    int ID; // Ma sach
    char BookTitle[20]; // Ten sach
    char Author[20]; // Ten tac gia
    char Type[2]; // Loai sach
    int MFGDate; // NXB
    int Price; // Gia tien
    int Amount; // So luong
};

void SetBook(BookStore &BS){
    printf("Ma sach: ");
    scanf("%d", &BS.ID);

    fflush(stdin);
    printf("Ten sach: ");
    gets(BS.BookTitle);

    fflush(stdin);
    printf("Tac gia: ");
    gets(BS.Author);

    fflush(stdin);
    printf("Loai sach: ");
    gets(BS.Type);

    printf("Nam xuat ban: ");
    scanf("%d", &BS.MFGDate);

    printf("Gia tien: ");
    scanf("%d", &BS.Price);

    printf("So luong: ");
    scanf("%d", &BS.Amount);
}

void GetBook(BookStore BS){
    printf("-========================-\n");
    printf("Ma sach: %d\n", BS.ID);
    printf("Ten sach: %s\n", BS.BookTitle);
    printf("Tac gia: %s\n", BS.Author);
    printf("Loai sach: %s\n", BS.Type);
    printf("Nam xuat ban: %d\n", BS.MFGDate);
    printf("Gia tien: %d\n", BS.Price);
    printf("So luong: %d\n", BS.Amount);
    printf("-========================-\n");
}

void ScanNum(int &n){
    printf("Nhap so luong san phan: 0 < n <= 100: ");
    do{
        scanf("%d", &n);
        if(n <= 0 || n > 100){
            printf("Qua so luong quy dinh!\n");
        }
    }while(n <= 0 || n > 100);
}

void SetBook_Array(BookStore BS[], int n){
    for(int i = 0; i < n; ++i){
        SetBook(BS[i]);
    }
}

void GetBook_Array(BookStore BS[], int n){
    for(int i = 0; i < n; ++i){
        GetBook(BS[i]);
    }
}

void AddBook_Array(BookStore BS[], int &n){
    n++;
    SetBook(BS[n-1]);
}

int SumPrice(BookStore BS[], int n){
    int value = 0;
    for(int i = 0; i < n; ++i){
        value += BS[i].Price * BS[i].Amount;
    }
    return value;
}

void _SwapBook(BookStore &BS1, BookStore &BS2){
    BookStore tg = BS1;
    BS1 = BS2;
    BS2 = tg;
}

void SortBook_ID(BookStore BS[], int n){
    for(int i = 0; i < n-1; ++i){
        for(int j = i+1; j < n; ++j){
            if(BS[i].ID > BS[j].ID){
                _SwapBook(BS[i], BS[j]);
            }
        }
    }
}

void FindBook_TitleBook(BookStore BS[], int n, char index[]){
    for(int i = 0; i < n; ++i){
        if(strcmp(BS[i].BookTitle, index) == 0){
            GetBook(BS[i]);
        }
    }
}

void FindBook_LessMFGDate(BookStore BS[], int n, int index){
    for(int i = 0; i < n; ++i){
        if(BS[i].MFGDate < index){
            GetBook(BS[i]);
        }
    }
}

int CntBook_ThanAmount(BookStore BS[], int n, int index){
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        if(BS[i].Amount > index){
            cnt++;
        }
    }
    return cnt;
}

void FindBook_Type(BookStore BS[], int n, char index[]){
    for(int i = 0; i < n; ++i){
        if(strcmp(BS[i].Type, index) == 0){
            GetBook(BS[i]);
        }
    }
}

int main(){
    int n, index;
    char c[20];
    BookStore BS[MAX];
    printf("-==============A==============-\n");
    ScanNum(n);
    SetBook_Array(BS, n);
    printf("-==============B==============-\n");
    GetBook_Array(BS, n);
    printf("-==============C==============-\n");
    AddBook_Array(BS, n);
    GetBook_Array(BS, n);
    printf("-==============D==============-\n");
    printf("Tong tien tat ca cuon sach: %d\n", SumPrice(BS, n));
    printf("-==============E==============-\n");
    SortBook_ID(BS, n);
    GetBook_Array(BS, n);
    printf("-==============F=============-\n");
    printf("Nhap ten sach can tim: ");
    fflush(stdin);
    gets(c);
    FindBook_TitleBook(BS, n, c);
    printf("-==============G=============-\n");
    printf("Nhap sach sau nam xuat ban: ");
    scanf("%d", &index);
    FindBook_LessMFGDate(BS, n, index);
    printf("-==============H==============-\n");
    printf("Dem so luong sach tren: ");
    scanf("%d", &index);
    printf("So luong sach tren %d la: %d\n", index, CntBook_ThanAmount(BS, n, index));
    printf("-==============H==============-\n");
    printf("Nhap loai sach can tim: ");
    fflush(stdin);
    gets(c);
    FindBook_Type(BS, n, c);

    return 0;
}
