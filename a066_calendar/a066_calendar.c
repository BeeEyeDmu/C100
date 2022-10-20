#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int zeller(int year, int month, int day);
void printWeekDays();
void printCalender(int year, int month, int w);

int main()
{
    int year, month, w;

    while (1) {
        printf("=> 년도와 월을 입력하세요 : ");
        scanf("%d %d", &year, &month);
        printWeekDays();
        w = zeller(year, month, 1); // 해당 월 1일의 요일을 찾습니다
        printCalender(year, month, w);
    }
}

void printWeekDays()
{
    char dayOfWeek[7][3] = { "일", "월", "화", "수", "목", "금", "토" };

    for (int i = 0; i < 7; i++)
        printf("%s\t", dayOfWeek[i]);
    printf("\n");
}

int zeller(int year, int month, int day)
{
    int w;

    if (month <= 2) {
        year -= 1;
        month += 12;
    }
    w = (year + year / 4 - year / 100 + year / 400 + (13 * month + 8) /
        5 + day) % 7;
    return w;
}

void printCalender(int year, int month, int w)
{
    int days[2][13] = {
        { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
        { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };

    int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (int i = 0; i < w; i++)
        printf("\t");
    for (int d = 1; d <= days[leap][month]; d++) {
        printf("%2d\t", d);
        if ((d + w) % 7 == 0)
            printf("\n");
    }
    printf("\n");
}