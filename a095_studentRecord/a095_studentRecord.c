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

// �޴� 1. �Է�
void insert()
{
    FILE* fp;
    student s;
    char buf[20] = {0};

    fp = fopen("students.txt", "a");

    //printf("Enter sid : ");
    //scanf("%d", &s.sid);
    //getchar();

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
    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }
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

// �޴� 4. �˻�
void search()
{
    FILE* fp;
    student s;
    int sid, found = 0;

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    printf("Enter sid : ");
    scanf("%d", &sid);
    while (fread(&s, sizeof(student), 1, fp)) {
        if (s.sid == sid) {
            found = 1;
            printf("%-10d%-10s", s.sid, s.name);
            for (int i = 0; i < 3; i++)
                printf("%6d", s.sub[i].score);
            printf("%6d%7.2f\n", s.total, s.average);
        }
    }
    if (found == 0)
        printf("Record Not Found!\n");
    fclose(fp);
}

// �޴� 5. ����
void update()
{
    FILE* fp, * fp1;
    student s;
    int sid, found = 0;

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fp1 = fopen("tmp.txt", "w");
    printf("Enter sid to update : ");
    scanf("%d", &sid);

    while (fread(&s, sizeof(student), 1, fp)) {
        if (s.sid == sid) {
            found = 1;
            s.total = 0;
            getchar();
            printf("Enter new name : ");
            scanf("%[^\n]", s.name);
            for (int i = 0; i < 3; i++) {
                printf("Enter score of subject %d :", i + 1);
                scanf("%d", &s.sub[i].score);
                s.total += s.sub[i].score;
            }
            s.average = s.total / 3.0;
        }
        fwrite(&s, sizeof(student), 1, fp1);
    }

    fclose(fp);
    fclose(fp1);
    if (found == 1) {
        remove("students.txt");
        rename("tmp.txt", "students.txt");
    }
    else
        printf("Record not Found!\n");
}

// �޴� 6. ����
void deleteStudent()
{
    FILE* fp, * fp1;
    student s;
    int sid, found = 0;

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fp1 = fopen("tmp.txt", "w");
    printf("Enter sid to delete : ");
    scanf("%d", &sid);

    while (fread(&s, sizeof(student), 1, fp)) {
        if (s.sid == sid)
            found = 1;
        else
            fwrite(&s, sizeof(student), 1, fp1);
    }

    fclose(fp);
    fclose(fp1);

    if (found == 1) {
        remove("students.txt");
        rename("tmp.txt", "students.txt");
    }
    else
        printf("Record not Found!\n");
}

// student.txt���� ������ �о s[]�� ����
student* readAndSaveStudent(int* n)
{
    student* s;
    FILE* fp;

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("No record found!\n");
        return;
    }

    fseek(fp, 0, SEEK_END);
    *n = ftell(fp) / sizeof(student);
    rewind(fp);

    s = (student*)calloc(*n, sizeof(student));

    for (int i = 0; i < *n; i++)
        fread(&s[i], sizeof(student), 1, fp);
    fclose(fp);

    return s;
}

// ���ĵ� s[]�� student.txt�� ����
void writeSorted(student* s, int n)
{
    FILE* fp;

    fp = fopen("students.txt", "w");
    for (int i = 0; i < n; i++)
        fwrite(&s[i], sizeof(student), 1, fp);
    fclose(fp);
}

// �޴� 7. ������ ����(��������)
void sortByScore()
{
    student* s, t;
    int n;

    s = readAndSaveStudent(&n);

    // sort by total
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (s[i].total < s[j].total) {
                t = s[i];
                s[i] = s[j];
                s[j] = t;
            }

    writeSorted(s, n);
    display();
}

// �޴� 8. �й����� ����(��������)
void sortBySid()
{
    student* s, t;
    int n;

    s = readAndSaveStudent(&n);

    // sort bt sid ascending
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (s[i].sid > s[j].sid) {
                t = s[i];
                s[i] = s[j];
                s[j] = t;
            }

    writeSorted(s, n);
    display();
}

// �޴� 9. �̸����� ����(��������)
void sortByName()
{
    student* s, t;
    int n;

    s = readAndSaveStudent(&n);

    // sort by Name ascending
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(s[i].name, s[j].name) > 0) {
                t = s[i];
                s[i] = s[j];
                s[j] = t;
            }

    writeSorted(s, n);
    display();
}

void menuSelect(int ch)
{
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
        search();
        break;
    case 5:
        update();
        break;
    case 6:
        deleteStudent();
        break;
    case 7:
        sortByScore();
        break;
    case 8:
        sortBySid();
        break;
    case 9:
        sortByName();
        //display();
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