#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int sid;
    char name[20];
    struct subject {
        int scode;
        char sname[20];
        int score;
    } sub[3];
    int total;
    float average;
} student;

void title() 
{
    printf("\t┏");
    for (int i = 0; i < strlen("STUDENT RECORD SYSTEM") + 1; i++)
        printf("━");
    printf("┓\n\t┃");
    printf(" STUDENT RECORD SYSTEM");
    printf("┃\n\t┗");
    for (int i = 0; i < strlen("STUDENT RECORD SYSTEM") + 1; i++)
        printf("━");
    printf("┛\n");
}

void menuDisplay() 
{
    title();
    printf(" 1. 입력");
    printf("\t\t 2. 레코드 개수");
    printf("\n 3. 전체 보기");
    printf("\t\t 4. 검색");
    printf("\n 5. 수정");
    printf("\t\t 6. 삭제");
    printf("\n 7. 점수로 정렬");
    printf("\t\t 8. 학번으로 정렬");
    printf("\n 9. 이름으로 정렬");
    printf("\t 0. 종료");
}

// 메뉴 1. 입력
void insert()
{
    FILE* fp;
    student s;
    char buf[20];

    fp = fopen("students.txt", "a");

    printf("Enter sid : ");
    scanf("%s", buf);
    getchar();
    for (int i = 0; buf[i] != '\0'; i++) {
        if (!isdigit(buf[i])) {
            printf("sid는 숫자이여야 합니다.\n");
            return 0;
        }
    }
    s.sid = atoi(buf);

    printf("Enter name : ");
    scanf("%[^\n]", s.name);

    s.total = 0;
    for (int i = 0; i < 3; i++) {
        printf("Enter score of subject %d :", i + 1);
        scanf("%d", &s.sub[i].score);
        s.total += s.sub[i].score;
    }
    s.average = s.total / 3.0;
    fwrite(&s, sizeof(student), 1, fp);
    fclose(fp);
}

// 메뉴 2. 레코드 개수
int nRecords()
{
    FILE* fp;
    student s;

    fp = fopen("students.txt", "r");
    fseek(fp, 0, SEEK_END);
    int n = ftell(fp) / sizeof(student);
    fclose(fp);
    return n;
}

// 메뉴 3. 전체 보기
void display()
{
    FILE* fp;
    student s;

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    if (nRecords() >= 1) {
        printf("%-10s%-10s", "학번", "이름");
        printf("%6s%6s%6s", "과목1", "과목2", "과목3");
        printf("%6s%6s\n", "총점", "평균");
        while (fread(&s, sizeof(student), 1, fp)) {
            printf("%-10d%-10s", s.sid, s.name);
            for (int i = 0; i < 3; i++)
                printf("%6d", s.sub[i].score);
            printf("%6d%7.2f\n", s.total, s.average);
        }
    }
    fclose(fp);
}

void menuSelect(int ch) {
    switch (ch) {
    case 1:
        insert();
        break;
    case 2:
        printf("No of records = %d\n", nRecords());
        break;
    case 3:
        display();
        break;
    case 4:
        //search();
        break;
    case 5:
        //update();
        break;
    case 6:
        //deleteStudent();
        break;
    case 7:
        //sortByScore();
        break;
    case 8:
        //sortBySid();
        break;
    case 9:
        //sortByName();
        break;
    }
}

int main()
{
    int choice = 0;

    do {
        menuDisplay();
        printf("\n => Enter Chioce: ");
        scanf("%d", &choice);
        menuSelect(choice);
    } while (choice != 0);
}