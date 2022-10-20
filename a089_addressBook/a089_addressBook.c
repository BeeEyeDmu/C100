#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
	int id;				// ��ȣ
	char name[20];		// �̸�
	char address[50];	    // �ּ�
	char phone[14];		// �ڵ���
	char email[30];		// e-mail
	struct person* next;	// ���� ��� ������
} person;

person* head = NULL;  // ����Ʈ�� ���
int lastId = 0;		// ������ ����� ��ȣ

void insertNode();		// ��� ���� �Լ�
void deleteNode();		// ��� ���� �Լ�
void display();	// ��� ���� ��� �Լ�
void save();		// ����Ʈ�� ���Ͽ� ����

void append(person* p)
{
	person* ptr, * temp;

	temp = (person*)malloc(sizeof(person));
	temp->id = p->id;
	strcpy(temp->name, p->name);
	strcpy(temp->address, p->address);
	strcpy(temp->phone, p->phone);
	strcpy(temp->email, p->email);
	temp->next = NULL;

	if (head == NULL) {
		head = temp;
	}
	else {
		ptr = head;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
}

void readFile()
{
	FILE* fp = fopen("address.txt", "a+");
	person p;

	while (fread(&p, sizeof(person), 1, fp)) {
		if (lastId < p.id)
			lastId = p.id;
		append(&p);
	}
	fclose(fp);
}

void save()
{
	FILE* fp = fopen("address.txt", "w+");

	for (person* ptr = head; ptr; ptr = ptr->next) {
		fwrite(ptr, sizeof(person), 1, fp);
	}
	fclose(fp);
}

int main()
{
	person* ptr;
	int choice;

	readFile();		// �ּҷ� ���� �о����

	do {
		printf("\n== �ּҷ� ���� �ý��� ==\n\n");
		printf(" 1. �� ��\n");
		printf(" 2. �� ��\n");
		printf(" 3. �� ��\n");
		printf(" 4. �� ��\n");
		printf(" 0. �� ��\n");
		printf("\n => �޴��� �����ϼ���: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			insertNode();
			display();
			break;
		case 2:
			display();
			break;
		case 3:
			deleteNode();
			display();
			break;
		case 4:
			save();
			break;
		}
	} while (choice != 0);
}

void insertNode()
{
	person* ptr, * temp;

	temp = (person*)malloc(sizeof(person));
	temp->next = NULL;

	temp->id = ++lastId;

	printf("�̸� : "); 	scanf(" %[^\n]s", temp->name);
	printf("�ּ� : ");	scanf(" %[^\n]s", temp->address);
	printf("��ȭ��ȣ : ");	scanf(" %s", temp->phone);
	printf("E-Mail : ");	scanf(" %s", temp->email);

	if (head == NULL)
		head = temp;
	else {
		for (ptr = head; ptr->next; ptr = ptr->next)
			;
		ptr->next = temp;
	}
}

void deleteNode()
{
	person* prev, * ptr = head, * tmp;
	int delId = 0;

	printf("������ Id�� �Է��ϼ���: ");
	scanf("%d", &delId);

	if (head == NULL) {
		printf("���� �����Ͱ� �����ϴ�.");
		return;
	}
	else if (head->id == delId) {
		ptr = head;
		head = head->next;
		free(ptr);
	}
	else {
		for (ptr = head; ptr->next; ptr = ptr->next) {
			prev = ptr;
			if (ptr->next->id == delId) {
				tmp = ptr->next;
				prev->next = ptr->next->next;
				free(tmp);
				break;
			}
		}
	}
}

void display()
{
	person* ptr = head;

	printf("----------------------------------------------------------------------------------------\n");
	printf("%-5s", "��ȣ");
	printf("%-20s", "�̸�");
	printf("%-30s", "�ּ�");
	printf("%-20s", "��ȭ��ȣ");
	printf("%-30s\n", "E-Mail");
	printf("----------------------------------------------------------------------------------------\n");


	while (ptr != NULL) {
		printf("%-5d", ptr->id);
		printf("%-20s", ptr->name);
		printf("%-30s", ptr->address);
		printf("%-20s", ptr->phone);
		printf("%-30s", ptr->email);
		printf("\n");
		ptr = ptr->next;
	}
	printf("----------------------------------------------------------------------------------------\n");
}