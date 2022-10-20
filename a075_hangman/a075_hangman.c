#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#define MAX_COUNT  200  // 사전의 최대 크기
#define BUFFER_SIZE 20  // 한 단어의 최대 길이

char words[MAX_COUNT][BUFFER_SIZE]; // 사전 배열
char inputs[BUFFER_SIZE];            // 사용자가 입력한 알파벳의 배열

int index;       // 문제로 출제된 단어의 index
int life = 10;   // 생명: 10개로 시작
int opens = 0;   // 맞춘 알파벳 수

int readDictionary();
void printHead();
void printWords(char ch[]);
int isInInputs(char);
void addInInputs(char c);

int main()
{
    char c;
    int count = readDictionary();

    printf("%d words read...\n", count);
    Sleep(1000);  // 1초 동안 대기

    srand(time(0));
    index = rand() % count;
    do {
        printHead();
        printf("알파벳을 입력하세요: ");
        c = _getche();
        addInInputs(c);
    } while (opens != strlen(words[index]) - 1 && life != 0);

    printHead();
    if (life == 0)
        printf("\n실패!! - 정답 : %s", words[index]);
    else
        printf("\n성공!!");
}

// 콘솔을 지우고 행맨게임의 헤드를 출력
void printHead()
{
    system("cls");
    printf("== HangMan!! ==\n");
    printf("\nLife = %d\n", life);
    // printf("%s", words[index]);  // 테스트용: 문제단어 표시
    printWords(inputs);
}

// 사전 파일에서 모든 단어 읽어오기
int readDictionary()
{
    FILE* fp;
    char line[20];  // line[]의 맨 뒤에는 '\n'이 들어있다
    int cnt = 0;    // 단어의 갯수

    fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error reading file \"dictionary.txt\"");
        exit(0);
    }

    while (1) {
        if (fgets(line, BUFFER_SIZE, fp) != NULL)
            strcpy(words[cnt++], line);
        else
            break;
    }
    fclose(fp);
    return cnt;
}

// 숨겨지거나 알려진 알파벳을 출력
void printWords(char input[])
{
    printf("┏");
    for (int i = 0; i < strlen(words[index]) - 1; i++)
        printf("━━");
    printf("┓\n┃");

    for (int i = 0; i < strlen(words[index]) - 1; i++)
        if (isInInputs(words[index][i]))
            printf(" %c", words[index][i]);
        else
            printf(" _");

    printf("┃\n┗");
    for (int i = 0; i < strlen(words[index]) - 1; i++) {
        printf("━━");
    }
    printf("┛\n");
}

// 문자 c가 이미 입력된 문자인지 체크
int isInInputs(char c)
{
    for (int i = 0; inputs[i] != '\0'; i++)
        if (inputs[i] == c)
            return 1;
    return 0;
}

// 입력된 알파벳 c를 inputs[] 배열에 저장
// 이미 저장되어 있는 문자라면 저장하지 않고 리턴
void addInInputs(char c)
{
    int i = 0;
    for (; inputs[i] != '\0'; i++)
        if (inputs[i] == c) {
            printf("\n이미 선택한 문자입니다.");
            Sleep(1000);
            return;
        }

    inputs[i] = c;
    life--;

    // words[index]에서 c의 갯수를 카운트
    for (i = 0; words[index][i] != '\0'; i++)
        if (words[index][i] == c)
            opens++;
}