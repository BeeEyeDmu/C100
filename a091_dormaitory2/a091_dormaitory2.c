#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define ROOMS  10

typedef struct dormitory {
    int sid;        // �й�
    char name[10];  // �̸�
    char home[10];  // �� �ּ�
    char gender[5]; // ����
    int roomNo;     // ������ �� ��ȣ
} dormitory;

// ������ �� ��ȣ
int allottedRooms = 0;  // ������ ���� ����
int rooms[] = { 101, 102, 201, 202, 301, 302, 401, 402, 501, 502 };
int roomAllotted[ROOMS] = { 0 };   // ���� ���� ����
dormitory dorms[ROOMS];

void menu()
{
    printf("\n== ����� ���� �ý��� ==\n");
    printf("   1. ���ο� �� ����\n");
    printf("   2. ���� ��� ���\n");
    printf("   3. ���� �ִ� �� ���\n");
    printf("   4. �� ���� ���\n");
    printf("   0. ����\n");
    printf(" >> ���ϴ� �޴��� �����ϼ���: ");
}

int getRoomNo()
{
    int rnd = rand() % ROOMS;

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

    dorms[allottedRooms] = dorm;
    allottedRooms++;

    for (int i = 0; i < ROOMS; i++)
        if (rooms[i] == dorm.roomNo) {
            roomAllotted[i] = 1;
            break;
        }
    
    printf("%s���� %dȣ�� �����Ǿ����ϴ�.\n", dorm.name, dorm.roomNo);
}

void display()
{
    printf("%10s%10s%10s%10s%10s\n",
        "�й�", "�̸�", "����", "����", "���ȣ");
    for (int i = 0; i < allottedRooms; i++) {
        printf("%10d%10s%10s%10s%10d\n",
            dorms[i].sid, dorms[i].name, dorms[i].home,
            dorms[i].gender, dorms[i].roomNo);
    }
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

    int id = 0;
    while (fread(&dorm, sizeof(dormitory), 1, fp)) {
        dorms[id].sid = dorm.sid;
        strcpy(dorms[id].name, dorm.name);
        strcpy(dorms[id].home, dorm.home);
        strcpy(dorms[id].gender, dorm.gender);
        dorms[id].roomNo = dorm.roomNo;
        allottedRooms++;
        for (int i = 0; i < ROOMS; i++)
            if (rooms[i] == dorm.roomNo) {
                roomAllotted[i] = 1;
                break;
            }
        id++;
    }
}

void writeDormitory() {
    dormitory dorm;
    FILE* fp = fopen("dormitory.txt", "w");  // ������ ���� �ۼ�

    for (int i = 0; i < allottedRooms; i++)
        fwrite(&dorms[i], sizeof(dormitory), 1, fp);
    fclose(fp);
}

void clearRoom(int roomNo)
{
    for (int i = 0; i < ROOMS; i++)
        if (rooms[i] == roomNo) {
            roomAllotted[i] = 0;
            allottedRooms--;
            break;
        }
}

void deleteRoom()
{
    int sid, deleting;

    printf("������ �л��� �й��� ���ּ���: ");
    scanf("%d", &sid);
    for (int i = 0; i < allottedRooms; i++)
        if (dorms[i].sid == sid) {
            deleting = i;
            clearRoom(dorms[i].roomNo);  // �� ���� ������� �����ϱ�
            break;
        }

    // dorms[] �迭�� ���Ҹ� ���ڸ��� ������ �̵�
    for (int i = deleting; i < allottedRooms; i++)
        dorms[i] = dorms[i + 1];
}

int main()
{
    int choice;

    srand(time(0));  // ���� �õ�
    readDormitory();
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
        case 4:
            deleteRoom();
            break;
        case 0:
            writeDormitory();
            break;
        }
    } while (choice != 0);
}