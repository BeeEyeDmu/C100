#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

void printDay(struct tm* t)
{
    char week[][3] = { "��", "��", "ȭ", "��", "��", "��", "��" };

    printf("%d�� %d�� %d�� %s����\n",
        t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, week[t->tm_wday]);
}

bool isLeapYear(int year)
{
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int dayOfYear(int y, int m, int d)
{
    int mDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int days = 0;

    for (int i = 1; i < m; i++)
        days += mDay[i];
    days += d;
    return isLeapYear(y) && m > 2 ? days + 1 : days;
}

int main()
{
    int bYear, bMonth, bDay;  // ����
    int tYear, tMonth, tDay;  // ����
    time_t now, birthday;
    struct tm* t, * birth;
    int totalDays = 0;

    printf("������ �Է��ϼ���(�� �� ��) : ");
    scanf("%d %d %d", &bYear, &bMonth, &bDay);

    time(&birthday);
    birth = localtime(&birthday);
    birth->tm_year = bYear - 1900;
    birth->tm_mon = bMonth - 1;
    birth->tm_mday = bDay;

    if (mktime(birth) == (time_t)(-1)) {
        printf("��� ������ ��¥(1970�� 1�� 1�� ����) �����Դϴ�.");
        return 0;
    }
    printDay(birth);

    time(&now);
    t = localtime(&now);
    printDay(t);

    tYear = t->tm_year + 1900;
    tMonth = t->tm_mon + 1;
    tDay = t->tm_mday;

    if (tYear != bYear) {
        // ������ 1�� 1�� ���� ���ñ����� ��¥ ��
        totalDays += dayOfYear(tYear, tMonth, tDay);

        // �¾ ���� ���Ϻ��� ������ �������� ��¥ ��
        int yearDays = isLeapYear(tYear) ? 366 : 365;
        totalDays += yearDays - dayOfYear(bYear, bMonth, bDay);

        // �� ������ �ų� ��¥ ��
        for (int y = bYear + 1; y < tYear; y++)
            totalDays += isLeapYear(y) ? 366 : 365;
    }
    else {
        totalDays = dayOfYear(tYear, tMonth, tDay)
            - dayOfYear(bYear, bMonth, bDay);
    }
    printf("���Ϻ��� ���ñ����� ��¥�� : %d��", totalDays);
}