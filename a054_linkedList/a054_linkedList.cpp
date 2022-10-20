#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void append();          // 리스트의 맨 뒤에 추가
void insert();          // 리스트의 맨 앞에 추가
void insert_pos();      // 특정 위치에 추가
void display();         // 리스트 출력

struct node
{
    int value;
    struct node* next;
};

struct node* head = NULL;

int main()
{
    int choice;

    while (1) {
        printf("\n============= MENU =============\n");
        printf(" 1.Append\n");
        printf(" 2.Insert\n");
        printf(" 3.Insert at position\n");
        printf(" 4.Display\n");
        printf(" 0.Exit\n");
        printf("-----------------------------------\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            append();
            break;
        case 2:
            insert();
            break;
        case 3:
            insert_pos();
            break;
        case 4:
            display();
            break;
        case 0:
            exit(0);
            break;
        }
    }
}

void append()   // 맨 뒤에 추가
{
    struct node* temp, * ptr;

    temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Out of Memory!\n");
        exit(0);
    }
    printf("\nEnter data :");
    scanf("%d", &temp->value);
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

void insert()   // 맨 앞에 추가
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));

    if (temp == NULL) {
        printf("Out of Memory!\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &temp->value);
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    }
    else {
        temp->next = head;
        head = temp;
    }
}

void insert_pos()  // 특정 위치에 추가
{
    struct node* ptr, * temp;
    int i, pos;

    temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Out of Memory!\n");
        return;
    }
    printf("Enter position to insert : ");
    scanf("%d", &pos);
    printf("Enter data : ");
    scanf("%d", &temp->value);
    temp->next = NULL;

    if (pos == 0) {
        temp->next = head;
        head = temp;
    }
    else {
        for (i = 0, ptr = head; i < pos - 1; i++) {
            ptr = ptr->next;
            if (ptr == NULL) {
                printf("Cannot insert at %d\n", pos);
                return;
            }
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

void display()  // 리스트 출력
{
    struct node* ptr = head;

    if (ptr == NULL) {
        printf("List is empty!\n");
        return;
    }
    else {
        printf(" List : ");
        while (ptr != NULL) {
            printf("%d ->\t", ptr->value);
            ptr = ptr->next;
        }
        printf("\n");
    }
}