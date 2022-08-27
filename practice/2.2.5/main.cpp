#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX 100
using ll = long long;

struct Date{
    int date;
    int month;
    int year;
};

typedef struct Student{
    char stId[11];
    char stName[50];
    Date stBirthday;
    char stGender;
    char stClass[8];
    float stScore;
}SV;

// Call function
void SetDate(Date &date);
void GetDate(Date date);
void SetStudent(Student &st);
void SetStudent_Arr(Student st[], int &n);
void GetStudent(Student st);
void GetStudent_Arr(Student st[], int n);
void StudentIT(Student st[], int n);
void StudentScoreThanN(Student st[], int n, int index);
int CountFemale(Student st[], int n);
void StudentMaxScore(Student st[], int n);
void InsertStudent(Student st[], int &n);
void FindAndDelete(Student st[], int &n, char index[]);
void SortStudent(Student st[], int n);
void Title();
int main()
{
    int n = 8; char strCmp[31];
    SV dataStudent[MAX] = {
        {"001", "Ngo Van Tien", {26,10,2003}, 'y', "21DTHC5", 10.0},
        {"002", "Vo Thanh Nam", {12,12,2002}, 'y', "21DTHC5", 1.0},
        {"003", "Nguyen Thi Ngoc Linh", {2,10,2003}, 'y', "21DTHC5", 1.0},
        {"004", "Ho Phuoc Nam", {2,1,2003}, 'y', "21DTHC5", 1.0},
        {"005", "Nguyen Hai Son", {2,10,2008}, 'y', "21DTHC5", 1.0},
        {"006", "Le Thi Thanh Ngan", {26,10,2003}, 'y', "21DTHC5", 1.0},
        {"007", "Doan Nguyen Huyen Trang", {26,10,2003}, 'y', "21DTHC5", 1.0},
        {"008", "Nguyen Thi Tuyet Mai", {26,10,2003}, 'y', "21DTHC5", 1.0},
    };
    GetStudent_Arr(dataStudent, n);
    StudentScoreThanN(dataStudent, n, 5);
    StudentIT(dataStudent, n);
    printf("So sinh vien nu: %d", CountFemale(dataStudent, n));
    printf("So sinh vien diem cao nhat:\n");
    StudentMaxScore(dataStudent, n);
    printf("Them 1 sinh vien: \n");
    InsertStudent(dataStudent, n);
    printf("Nhap ten 1 sinh vien X va xoa: \n");
    fflush(stdin);
    gets(strCmp);
    FindAndDelete(dataStudent, n, strCmp);
    printf("Sap xep sinh vien theo diem trung binh tang dan: \n");
    SortStudent(dataStudent, n);
    GetStudent_Arr(dataStudent, n);
    return 0;
}

void ScanNum(int &n){
    printf("Nhap so luong : 0 < n <= 100: ");
    do{
        scanf("%d", &n);
        if(n <= 0 || n > 100){
            printf("Qua so luong quy dinh!\n");
        }
    }while(n <= 0 || n > 100);
}

// Set Date
void SetDate(Date &date){
    printf("Ngay: ");
    scanf("%u", &date.date);
    printf("Thang: ");
    scanf("%u", &date.month);
    printf("Nam: ");
    scanf("%d", &date.year);
}
// Get Date
void GetDate(Date date){
    printf("%d/%d/%d", date.date, date.month, date.year);
}
// Nhap 1 sinh vien
void SetStudent(Student &st){
    //ID Student
    printf("MSSV: ");
    scanf("%s", &st.stId);
    // Name
    printf("Ten: ");
    fflush(stdin);
    gets(st.stName);
    // Birhtday
    SetDate(st.stBirthday);
    // Gender
    do{
        printf("x-Female , y-Male: ");
        st.stGender = getche();
    }while(st.stGender != 'x' && st.stGender != 'y');
    // Class
    printf("\nLop: ");
    scanf("%s", &st.stClass);
    // Score
    printf("Diem trung binh: ");
    scanf("%f", &st.stScore);
}

// Nhap N sinh vien
void SetStudent_Arr(Student st[], int &n){
    ScanNum(n);
    for(int i = 0; i < n; ++i){
        SetStudent(st[i]);
    }
}
void Title(){
    printf("\n   STT  \t\t\tTen\tLop\t\tGioi tinh\tNgay sinh\tLop\tDiem");
}
// Xuat 1 sinh vien
void GetStudent(Student st){
    printf("\n%6s\t|%30s", st.stId, st.stName);
    if(st.stGender == 'x') printf("|\tFemale");
    else printf("|\tMale\t");
    GetDate(st.stBirthday);
    printf("\t|%9s\t|Score: %.1f\n\n", st.stClass, st.stScore);
}
// Xuat N sinh vien
void GetStudent_Arr(Student st[], int n){
    Title();
    for(int i = 0; i < n; ++i){
        GetStudent(st[i]);
    }
}
// Xuat DTB SV > index
void StudentScoreThanN(Student st[], int n, int index){
    for(int i = 0; i < n; i++){
        if(st[i].stScore > index)
            GetStudent(st[i]);
    }
}
// Xuat SV IT
void StudentIT(Student st[], int n){
    printf("Sinh vien IT: \n");
    for(int i = 0; i < n; ++i){
        if(st[i].stClass[5] == 'I' && st[i].stClass[6] == 'T'){
            GetStudent(st[i]);
        }
    }
}

int CountFemale(Student st[], int n){
    int res = 0;
    for(int i = 0; i < n; ++i){
        if(st[i].stGender == 'x'){
            res++;
        }
    }
    return res;
}

void StudentMaxScore(Student st[], int n){
    float _maxScore = st[0].stScore;
    for(int i = 1; i < n; ++i){
        if(_maxScore < st[i].stScore){
            _maxScore = st[i].stScore;
        }
    }
    for(int i = 0; i < n; ++i){
        if(st[i].stScore == _maxScore){
            GetStudent(st[i]);
        }
    }
}

void InsertStudent(Student st[], int &n){
    ++n;
    SetStudent(st[n]);
}

void RemoveStudent(Student st[], int &n, int index){
    for(int i = index; i < n-1; ++i){
        st[i] = st[i+1];
    }
    n--;
}

void FindAndDelete(Student st[], int &n, char index[]){
    for(int i = 0; i < n; ++i){
        if(strcmp(index, st[i].stId) == 0){
            RemoveStudent(st, n, i);
        }
    }
    printf("Find and delete successful!\n");
}

void _swapStudent(Student &st1, Student &st2){
    Student tg = st1;
    st1 = st2;
    st2 = tg;
}

void SortStudent(Student st[], int n){
    for(int i = 0; i < n-1; ++i){
        for(int j = i+1; j < n; ++j){
            if(st[i].stScore > st[j].stScore){
                _swapStudent(st[i], st[j]);
            }
        }
    }
}