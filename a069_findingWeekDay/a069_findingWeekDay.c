#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
	int year, month, day;
} sDay;

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

// �� ��¥ ���� ��¥ ���� ���
int calcTotalDays(sDay* base, sDay* the)
{
	int totalDays = 0;

	if (base->year != the->year) {
		totalDays += dayOfYear(the->year, the->month, the->day);
		int yearDays = isLeapYear(base->year) ? 366 : 365;
		totalDays += yearDays
			- dayOfYear(base->year, base->month, base->day);
		for (int y = base->year + 1; y < the->year; y++)
			totalDays += isLeapYear(y) ? 366 : 365;
	}
	else {
		totalDays = dayOfYear(the->year, the->month, the->day)
			- dayOfYear(base->year, base->month, base->day);
	}
	return totalDays;
}

int main()
{
	sDay baseDay = { 1900, 1, 1 };
	sDay theDay;
	int tYear, tMonth, tDay;
	int totalDays = 0;
	char week[][3] = { "��", "��", "ȭ", "��", "��", "��", "��" };

	printf("������ �˰� ���� ��¥�� �Է��ϼ���(�� �� ��) : ");
	scanf("%d%d%d", &theDay.year, &theDay.month, &theDay.day);

	totalDays = calcTotalDays(&baseDay, &theDay);
	printf("total days from 1900/1/1 : %d\n", totalDays);

	printf("%d�� %d�� %d�� = %s����\n", theDay.year,
		theDay.month, theDay.day, week[(1 + totalDays % 7) % 7]);
}