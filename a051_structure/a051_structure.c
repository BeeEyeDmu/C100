#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct student {
	char dept[20];
	int year;
	int id;
	char name[20];
	char phone[20];
};

void printInfo(struct student* s)
{
	printf("\n�а� : %s\n", s->dept);
	printf("�г� : %d\n", s->year);
	printf("�й� : %d\n", s->id);
	printf("�̸� : %s\n", s->name);
	printf("��ȭ��ȣ : %s\n", s->phone);
}

int main()
{
	struct student s;

	printf("�а� : ");
	scanf("%s", s.dept);
	printf("�г� : ");
	scanf("%d", &s.year);
	printf("�й� : ");
	scanf("%d", &s.id);
	printf("�̸� : ");
	scanf("%s", s.name);
	printf("��ȭ��ȣ : ");
	scanf("%s", s.phone);

	printInfo(&s);
}