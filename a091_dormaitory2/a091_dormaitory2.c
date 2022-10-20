#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define ROOMS  10

typedef struct dormitory {
    int sid;        // 학번
    char name[10];  // 이름
    char home[10];  // 집 주소
    char gender[5]; // 성별
    int roomNo;     // 배정된 방 번호
} dormitory;

// 배정할 방 번호
int allottedRooms = 0;  // 배정된 방의 갯수
int rooms[] = { 101, 102, 201, 202, 301, 302, 401, 402, 501, 502 };
int roomAllotted[ROOMS] = { 0 };   // 방의 배정 여부
dormitory dorms[ROOMS];

void menu()
{
    printf("\n== 기숙사 배정 시스템 ==\n");
    printf("   1. 새로운 방 배정\n");
    printf("   2. 배정 결과 출력\n");
    printf("   3. 남아 있는 방 출력\n");
    printf("   4. 방 배정 취소\n");
    printf("   0. 종료\n");
    printf(" >> 원하는 메뉴를 선택하세요: ");
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

    dorms[allottedRooms] = dorm;
    allottedRooms++;

    for (int i = 0; i < ROOMS; i++)
        if (rooms[i] == dorm.roomNo) {
            roomAllotted[i] = 1;
            break;
        }
    
    printf("%s님은 %d호에 배정되었습니다.\n", dorm.name, dorm.roomNo);
}

void display()
{
    printf("%10s%10s%10s%10s%10s\n",
        "학번", "이름", "지역", "성별", "방번호");
    for (int i = 0; i < allottedRooms; i++) {
        printf("%10d%10s%10s%10s%10d\n",
            dorms[i].sid, dorms[i].name, dorms[i].home,
            dorms[i].gender, dorms[i].roomNo);
    }
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
    FILE* fp = fopen("dormitory.txt", "w");  // 파일을 새로 작성

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

    printf("삭제할 학생의 학번을 써주세요: ");
    scanf("%d", &sid);
    for (int i = 0; i < allottedRooms; i++)
        if (dorms[i].sid == sid) {
            deleting = i;
            clearRoom(dorms[i].roomNo);  // 이 방을 빈방으로 수정하기
            break;
        }

    // dorms[] 배열의 원소를 한자리씩 앞으로 이동
    for (int i = deleting; i < allottedRooms; i++)
        dorms[i] = dorms[i + 1];
}

int main()
{
    int choice;

    srand(time(0));  // 랜덤 시드
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