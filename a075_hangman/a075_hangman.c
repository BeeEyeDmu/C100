#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#define MAX_COUNT  200  // ������ �ִ� ũ��
#define BUFFER_SIZE 20  // �� �ܾ��� �ִ� ����

char words[MAX_COUNT][BUFFER_SIZE]; // ���� �迭
char inputs[BUFFER_SIZE];            // ����ڰ� �Է��� ���ĺ��� �迭

int index;       // ������ ������ �ܾ��� index
int life = 10;   // ����: 10���� ����
int opens = 0;   // ���� ���ĺ� ��

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
    Sleep(1000);  // 1�� ���� ���

    srand(time(0));
    index = rand() % count;
    do {
        printHead();
        printf("���ĺ��� �Է��ϼ���: ");
        c = _getche();
        addInInputs(c);
    } while (opens != strlen(words[index]) - 1 && life != 0);

    printHead();
    if (life == 0)
        printf("\n����!! - ���� : %s", words[index]);
    else
        printf("\n����!!");
}

// �ܼ��� ����� ��ǰ����� ��带 ���
void printHead()
{
    system("cls");
    printf("== HangMan!! ==\n");
    printf("\nLife = %d\n", life);
    // printf("%s", words[index]);  // �׽�Ʈ��: �����ܾ� ǥ��
    printWords(inputs);
}

// ���� ���Ͽ��� ��� �ܾ� �о����
int readDictionary()
{
    FILE* fp;
    char line[20];  // line[]�� �� �ڿ��� '\n'�� ����ִ�
    int cnt = 0;    // �ܾ��� ����

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

// �������ų� �˷��� ���ĺ��� ���
void printWords(char input[])
{
    printf("��");
    for (int i = 0; i < strlen(words[index]) - 1; i++)
        printf("����");
    printf("��\n��");

    for (int i = 0; i < strlen(words[index]) - 1; i++)
        if (isInInputs(words[index][i]))
            printf(" %c", words[index][i]);
        else
            printf(" _");

    printf("��\n��");
    for (int i = 0; i < strlen(words[index]) - 1; i++) {
        printf("����");
    }
    printf("��\n");
}

// ���� c�� �̹� �Էµ� �������� üũ
int isInInputs(char c)
{
    for (int i = 0; inputs[i] != '\0'; i++)
        if (inputs[i] == c)
            return 1;
    return 0;
}

// �Էµ� ���ĺ� c�� inputs[] �迭�� ����
// �̹� ����Ǿ� �ִ� ���ڶ�� �������� �ʰ� ����
void addInInputs(char c)
{
    int i = 0;
    for (; inputs[i] != '\0'; i++)
        if (inputs[i] == c) {
            printf("\n�̹� ������ �����Դϴ�.");
            Sleep(1000);
            return;
        }

    inputs[i] = c;
    life--;

    // words[index]���� c�� ������ ī��Ʈ
    for (i = 0; words[index][i] != '\0'; i++)
        if (words[index][i] == c)
            opens++;
}