#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROOMS  10

typedef struct dormitory {
    int sid;        // 학번
    char name[10];  // 이름
    char home[10];  // 집 주소
    char gender[5]; // 성별
    int roomNo;     // 배정된 방 번호
} dormitory;

int allottedRooms = 0;  // 배정된 방의 갯수

// 배정할 방 번호
int rooms[] = { 101, 102, 201, 202, 301, 302, 401, 402, 501, 502 };
int roomAllotted[ROOMS] = { 0 };   // 방의 배정 여부

void menu()
{
    printf("\n== 기숙사 배정 시스템 ==\n");
    printf("   1. 새로운 방 배정\n");
    printf("   2. 배정 결과 출력\n");
    printf("   3. 남아 있는 방 출력\n");
    printf("   0. 종료\n");
    printf(" >> 원하는 메뉴를 선택하세요: ");
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
        printf("빈 방이 없습니다\n");
        return;
    }
    printf("학번 : ");
    scanf("%d", &dorm.sid);
    printf("이름 : ");
    scanf("%s", dorm.name);
    printf("지역 : ");
    scanf("%s", &dorm.home);
    printf("성별(남/여) : ");
    scanf("%s", dorm.gender);

    dorm.roomNo = getRoomNo();
    allottedRooms++;
    roomAllotted[dorm.roomNo] = 1;
    printf("%s님은 %d호에 배정되었습니다.\n", dorm.name, dorm.roomNo);

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
        "학번", "이름", "지역", "성별", "방번호");
    while (fread(&dorm, sizeof(dormitory), 1, fp)) {
        printf("%10d%10s%10s%10s%10d\n",
            dorm.sid, dorm.name, dorm.home, dorm.gender, dorm.roomNo);
    }
    fclose(fp);
}

void printAvailable()
{
    printf(" 배정된 방 수 : %d\n", allottedRooms);
    printf(" 배정가능한 방 수 : %d\n", ROOMS - allottedRooms);
    printf(" 배정가능한 방 번호 : ");

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

    srand(time(0)); // 랜덤 방 배정을 위한 시드 설정
    readDormitory(); // 파일에서 배정된 방의 정보를 읽기
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