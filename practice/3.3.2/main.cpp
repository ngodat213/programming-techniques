#include<stdio.h>
#include<string.h>
class Dimens{
    public:
        int cntClass = 0;
        int MaxNum = 100;
        int MinNum = 0;
        int MaxScore = 10;
        int MinScore = 0;
        char Male = 'y';
        char Female = 'x';
        char IT[3] = "IT";
};

typedef struct Date{
    int date;
    int month;
    int year;
};

typedef struct Student{
    char Name[50];
    int Id;
    char Gender;
    char Class[6];
    float ScoreMath;
    float ScorePhysics;
    float ScoreIT;
    int n; // it means which class is in the class data
};

Dimens dimens;

void SetNum(int &n){
    Dimens dimen;
    printf("Nhap n, 0 < n <= 100: ");
    do{
        scanf("%d", &n);
        if(n <= dimen.MinNum || n > dimen.MaxNum){
            printf("Qua so luong quy dinh!\n");
        }
    }while(n <= dimen.MinNum || n > dimen.MaxNum);
}

bool isMale(char c){
    if(c == dimens.Male) return 1;
    return 0;
}

bool isScore(float n){
    if(n >= dimens.MinScore && n <= dimens.MaxScore) return 1;
    return 0;
}

bool isGender(char c){
    if(c == dimens.Male || c == dimens.Female) return 1;
    return 0;
}

int isOldClass(Student *st, int n, Student *stCmp){
    int pos = 0;
    for(int i = 0; i < n; i++){
        if(strcmp((st+i)->Class, stCmp->Class) == 0){
            pos = i;
        }
    }
    return pos;
}

void SetStudent(Student *st){
    // Name
    printf("Ten: ");
    fflush(stdin);
    gets(st->Name);
    // ID
    printf("Ma so: ");
    scanf("%d", &st->Id);
    // Gender
    printf("Gioi tinh x-nam, y-nu: ");
    do{
        fflush(stdin);
        scanf("%c", &st->Gender);
        if(!isGender(st->Gender))
            printf("Nhap lai!\n");
    }while(!isGender(st->Gender));

    // Class
    printf("Lop: ");
    fflush(stdin);
    gets(st->Class);
    // ScoreMath
    printf("Diem toan: ");
    do{
        scanf("%f", &st->ScoreMath);
        if(!isScore(st->ScoreMath))
            printf("Nhap lai!\n");
    }while(!isScore(st->ScoreMath));
    // ScorePhysics
    printf("Diem vat ly: ");
    do{
        scanf("%f", &st->ScorePhysics);
        if(!isScore(st->ScorePhysics))
            printf("Nhap lai!\n");
    }while(!isScore(st->ScorePhysics));
    // ScoreIT
    printf("Diem tin hoc: ");
    do{
        scanf("%f", &st->ScoreIT);
        if(!isScore(st->ScoreIT))
            printf("Nhap lai!\n");
    }while(!isScore(st->ScoreIT));
}

void GetStudent(Student *st){
    printf("\tTen: %s\n", st->Name);
    printf("\tMa so: %d\n", st->Id);
    printf("\tGioi tinh: %s\n", isMale(st->Gender)? "Nam" : "Nu");
    printf("\tLop: %s\n", st->Class);
    printf("\tDiem toan: %f\n", st->ScoreMath);
    printf("\tDiem vat ly: %f\n", st->ScorePhysics);
    printf("\tDiem tin hoc: %f\n", st->ScoreIT);
}

void SetStudent_Arr(Student *st, int &n){
    SetNum(n);
    for(int i = 0; i < n; ++i){
        SetStudent(st+i);
        // Kiem tra xem st->Class co trong danh sach student khong
        // Neu khong gan st->n bang dimens.cntClass + 1;
        int _isOldClass = isOldClass(st, n, st+i);
        if(_isOldClass == 0){
            (st+i)->n = &dimens.cntClass++;
        }else{
            (st+i)->n = &_isOldClass;
        }
    }
}

void GetStudent_Arr(Student *st, int n){
    printf("-=================List Student=================-\n");
    for(int i = 0; i < n; ++i){
        printf(".:Student[%d]:.\n\n", i);
        GetStudent(st+i);
    }
}

void GetStudent_ID(Student *st, int n, int idCmp){
    for(int i = 0; i < n; ++i){
        if((st+i)->Id == idCmp){
            GetStudent(st+i);
            return;
        }
    }
}

void GetStudent_Class(Student *st, int n, char classCmp[]){
    for(int i = 0; i < n; ++i){
        if(strcmp((st+i)->Class, classCmp) == 0){
            GetStudent(st+i);
        }
    }
}

void GetStudentIsFemale_Class(Student *st, int n, char classCmp[]){
    for(int i = 0; i < n; ++i){
        if(strcmp((st+i)->Class, classCmp) == 0 && !isMale((st+i)->Gender)){
            GetStudent(st+i);
        }
    }
}

void GetStudent_Name(Student *st, int n, char nameCmp[]){
    for(int i = 0; i < n; ++i){
        if(strcmp((st+i)->Name, nameCmp) == 0){
            GetStudent(st+i);
        }
    }
}

void _swapStudent(Student *st1, Student *st2){
    Student *tg = st1;
    st1 = st2;
    st2 = tg;
}

void ShowStudent_Class(Student *st, int n){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if((st+j)->n == i){
                GetStudent(st+j);
            }
        }
    }
}

int main(){
    int n;
    Student *st = new Student[dimens.MaxNum];
    SetStudent_Arr(st, n);
    ShowStudent_Class(st, n);
    printf("%d", dimens.cntClass);
    return 0;
}
