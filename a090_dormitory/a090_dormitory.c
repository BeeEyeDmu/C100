#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROOMS  10

typedef struct dormitory {
    int sid;        // �й�
    char name[10];  // �̸�
    char home[10];  // �� �ּ�
    char gender[5]; // ����
    int roomNo;     // ������ �� ��ȣ
} dormitory;

int allottedRooms = 0;  // ������ ���� ����

// ������ �� ��ȣ
int rooms[] = { 101, 102, 201, 202, 301, 302, 401, 402, 501, 502 };
int roomAllotted[ROOMS] = { 0 };   // ���� ���� ����

void menu()
{
    printf("\n== ����� ���� �ý��� ==\n");
    printf("   1. ���ο� �� ����\n");
    printf("   2. ���� ��� ���\n");
    printf("   3. ���� �ִ� �� ���\n");
    printf("   0. ����\n");
    printf(" >> ���ϴ� �޴��� �����ϼ���: ");
}

int getRoomNo()
{   
    int rnd = rand() % ROOMS;

    //printf("rnd = %d\n", rnd);
    if (roomAllotted[rnd] == 0) {
        roomAllotted[rnd] = 1;
        return rooms[rnd];
    }
    else
        getRoomNo();
}

void allotARoom()
{
    dormitory dorm;
    FILE* fp = fopen("dormitory.txt", "a+");

    if (allottedRooms >= ROOMS) {
        printf("�� ���� �����ϴ�\n");
        return;
    }
    printf("�й� : ");
    scanf("%d", &dorm.sid);
    printf("�̸� : ");
    scanf("%s", dorm.name);
    printf("���� : ");
    scanf("%s", &dorm.home);
    printf("����(��/��) : ");
    scanf("%s", dorm.gender);

    dorm.roomNo = getRoomNo();
    allottedRooms++;
    roomAllotted[dorm.roomNo] = 1;
    printf("%s���� %dȣ�� �����Ǿ����ϴ�.\n", dorm.name, dorm.roomNo);

    fwrite(&dorm, sizeof(dormitory), 1, fp);
    fclose(fp);
}

void display()
{
    dormitory dorm;

    FILE* fp = fopen("dormitory.txt", "r");
    if (fp == NULL)
        return;
    printf("%10s%10s%10s%10s%10s\n",
        "�й�", "�̸�", "����", "����", "���ȣ");
    while (fread(&dorm, sizeof(dormitory), 1, fp)) {
        printf("%10d%10s%10s%10s%10d\n",
            dorm.sid, dorm.name, dorm.home, dorm.gender, dorm.roomNo);
    }
    fclose(fp);
}

void printAvailable()
{
    printf(" ������ �� �� : %d\n", allottedRooms);
    printf(" ���������� �� �� : %d\n", ROOMS - allottedRooms);
    printf(" ���������� �� ��ȣ : ");

    for (int i = 0; i < ROOMS; i++) {
        if (roomAllotted[i] == 0)
            printf("%5d ", rooms[i]);
    }
    printf("\n");
}

void readDormitory()
{
    dormitory dorm;

    FILE* fp = fopen("dormitory.txt", "r");
    if (fp == NULL) { return; }
    while (fread(&dorm, sizeof(dormitory), 1, fp)) {
        for (int i = 0; i < ROOMS; i++)
            if (rooms[i] == dorm.roomNo) {
                roomAllotted[i] = 1;
                allottedRooms++;
            }
    }
}

int main()
{
    int choice;

    srand(time(0)); // ���� �� ������ ���� �õ� ����
    readDormitory(); // ���Ͽ��� ������ ���� ������ �б�
    do {
        menu();
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            allotARoom();
            break;
        case 2:
            display();
            break;
        case 3:
            printAvailable();
            break;
        case 0:
            break;
        }
    } while (choice != 0);
}