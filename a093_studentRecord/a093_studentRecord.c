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

void menuDisplay() 
{
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

// �޴� 1. �Է�
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
            printf("sid�� �����̿��� �մϴ�.\n");
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

// �޴� 2. ���ڵ� ����
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

// �޴� 3. ��ü ����
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
        printf("%-10s%-10s", "�й�", "�̸�");
        printf("%6s%6s%6s", "����1", "����2", "����3");
        printf("%6s%6s\n", "����", "���");
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