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

void title() {
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

void menuDisplay() {
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

void menuSelect(int ch) {
    switch (ch) {
    case 1:
        //insert();
        break;
    case 2:
        //printf("No of records = %d\n", nRecords());
        break;
    case 3:
        //display();
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