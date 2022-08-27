#include<stdio.h>
#include<string.h>
#define PATH "D:\\test\\test.txt"

bool NguyenAm(char c){
	switch(c) {
        case 'o':
        case 'O':
        case 'u':
        case 'U':
        case 'i':
        case 'I':
        case 'a':
        case 'A':
        case 'e':
        case 'E':
            return 1;
    }
    return 0;
}

void LuuFile(char path[], char c[]){
	FILE *f = fopen(PATH, "r+");
	if(f == NULL)
		printf("Khong mo duoc file\n");
	for(int i = 0; i < strlen(c); ++i){
		if(NguyenAm(c[i]))
			fprintf(f, "%c ", c[i]);
	}
	fclose(f);
}

void DocFile(char path[]){
	FILE *f = fopen(PATH, "r+");
	if(f == NULL)
		printf("Khong mo duoc file\n");
	char c;
	while(!feof(f)){
		fscanf(f, "%c", &c);
		printf("%c ", c);
	}
	fclose(f);
}

int main(){
	char c[] = "ngo van tien dat";
	LuuFile(PATH, c);
	DocFile(PATH);
	return 0;	
}
