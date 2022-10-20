#include <stdio.h>

int daytable[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int day_of_year(int year, int month, int day)
{
	int leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (int i = 1; i < month; i++)
		day += daytable[leap][i];
	return day;
}

void month_day(int year, int yearday, int* pmonth, int* pday)
{
	int leap, i;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (i = 1; yearday > daytable[leap][i]; i++)
		yearday -= daytable[leap][i];
	*pmonth = i;
	*pday = yearday;
}

int main()
{
	int month, day;

	printf("2022�� 11�� 22���� 2022���� %d��° ���Դϴ�.\n",
		day_of_year(2022, 11, 22));
	month_day(2022, 300, &month, &day);
	printf("2022���� 300��° ���� %d�� %d���Դϴ�.\n", month, day);
}