#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int year, month, day, w;
	char dayOfWeek[7][3] = { "��", "��", "ȭ", "��", "��", "��", "��" };

	printf("�� �� �� �Է�: ");
	scanf("%d %d %d", &year, &month, &day);

	// ������ �������� ���� ���
	if (month <= 2) {
		year -= 1;
		month += 12;
	}

	w = (year + year / 4 - year / 100 + year / 400 + (13 * month + 8) / 5 + day) % 7;

	printf("%s����\n", dayOfWeek[w]);
}