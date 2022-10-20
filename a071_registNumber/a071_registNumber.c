#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int checkNumber(char regNum[]);

int main()
{
    char regNum[14];

    printf("주민등록번호 13자리를 입력하세요 : ");
    //scanf_s("%s", regNum, sizeof(regNum));
    scanf("%s", regNum);

    int check = checkNumber(regNum);
    if (check == regNum[12] - '0')
        printf("유효한 주민등록번호입니다.\n");
    else
        printf("유효하지 않은 주민등록번호입니다.\n");
}

int checkNumber(char regNum[])
{
    int origin[13];
    int chk[12] = { 2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5 };
    int chkSum = 0;

    for (int i = 0; i < 13; i++)
        origin[i] = regNum[i] - '0';
    for (int i = 0; i < 12; i++)
        chkSum += origin[i] * chk[i];
    return (11 - chkSum % 11) % 10;
}