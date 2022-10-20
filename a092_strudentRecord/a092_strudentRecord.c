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
    printf("\t��");
    for (int i = 0; i < strlen("STUDENT RECORD SYSTEM") + 1; i++)
        printf("��");
    printf("��\n\t��");
    printf(" STUDENT RECORD SYSTEM");
    printf("��\n\t��");
    for (int i = 0; i < strlen("STUDENT RECORD SYSTEM") + 1; i++)
        printf("��");
    printf("��\n");
}

void menuDisplay() {
    title();
    printf(" 1. �Է�");
    printf("\t\t 2. ���ڵ� ����");
    printf("\n 3. ��ü ����");
    printf("\t\t 4. �˻�");
    printf("\n 5. ����");
    printf("\t\t 6. ����");
    printf("\n 7. ������ ����");
    printf("\t\t 8. �й����� ����");
    printf("\n 9. �̸����� ����");
    printf("\t 0. ����");
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