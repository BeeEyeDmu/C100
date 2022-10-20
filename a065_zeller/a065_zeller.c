#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int year, month, day, w;
	char dayOfWeek[7][3] = { "일", "월", "화", "수", "목", "금", "토" };

	printf("년 월 일 입력: ");
	scanf("%d %d %d", &year, &month, &day);

	// 제라의 공식으로 요일 계산
	if (month <= 2) {
		year -= 1;
		month += 12;
	}

	w = (year + year / 4 - year / 100 + year / 400 + (13 * month + 8) / 5 + day) % 7;

	printf("%s요일\n", dayOfWeek[w]);
}