#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
	int id;				// 번호
	char name[20];		// 이름
	char address[50];	    // 주소
	char phone[14];		// 핸드폰
	char email[30];		// e-mail
	struct person* next;	// 다음 노드 포인터
} person;

person* head = NULL;  // 리스트의 헤드
int lastId = 0;		// 마지막 사람의 번호

void insertNode();		// 노드 삽입 함수
void deleteNode();		// 노드 삭제 함수
void display();	// 노드 정보 출력 함수
void save();		// 리스트를 파일에 저장

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

	readFile();		// 주소록 파일 읽어오기

	do {
		printf("\n== 주소록 관리 시스템 ==\n\n");
		printf(" 1. 등 록\n");
		printf(" 2. 출 력\n");
		printf(" 3. 삭 제\n");
		printf(" 4. 저 장\n");
		printf(" 0. 종 료\n");
		printf("\n => 메뉴를 선택하세요: ");
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

	printf("이름 : "); 	scanf(" %[^\n]s", temp->name);
	printf("주소 : ");	scanf(" %[^\n]s", temp->address);
	printf("전화번호 : ");	scanf(" %s", temp->phone);
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

	printf("삭제할 Id를 입력하세요: ");
	scanf("%d", &delId);

	if (head == NULL) {
		printf("아직 데이터가 없습니다.");
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
	printf("%-5s", "번호");
	printf("%-20s", "이름");
	printf("%-30s", "주소");
	printf("%-20s", "전화번호");
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