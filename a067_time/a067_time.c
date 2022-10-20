#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>

void printDayTime(struct tm* t)
{
	char week[][3] = { "��", "��", "ȭ", "��", "��", "��", "��" };
	char ampm[5] = "����";

	if (t->tm_hour > 12) {
		t->tm_hour -= 12;
		strcpy(ampm, "����");
	}

	printf("%d�� %d�� %d�� %s���� %s %d:%d:%d\n",
		t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
		week[t->tm_wday], ampm, t->tm_hour, t->tm_min, t->tm_sec);
}

int main()
{
	struct tm* t;
	time_t now;

	time(&now);
	printf("time = %ul\n", now);

	t = localtime(&now);
	printf("asctime = %s", asctime(t));

	printDayTime(t);
}