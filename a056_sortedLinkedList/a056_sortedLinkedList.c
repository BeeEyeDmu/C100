#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

void insert_list();    // 리스트에 추가
void delete_list();    // 리스트에서 삭제
void display();   // 리스트 출력

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
        printf(" 1.Insert\n");
        printf(" 2.Delete\n");
        printf(" 3.Dislay\n");
        printf(" 0.Exit\n");
        printf("-----------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            insert_list();
            display();
            break;
        case 2:
            delete_list();
            display();
            break;
        case 3:
            display();
            break;
        case 0:
            exit(0);
            break;
        }
    }
}

void display()
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

void insert_list()
{
    struct node* ptr, * temp;
    int i, value;

    temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Out of Memory!\n");
        return;
    }
    printf("Enter data : ");
    scanf("%d", &value);
    temp->value = value;
    temp->next = NULL;

    if (head == NULL) // 빈 리스트
        head = temp;
    else if (head->value > value) { // 맨 앞에 추가
        temp->next = head;
        head = temp;
    }
    else {
        for (ptr = head; ptr->next; ptr = ptr->next) {
            if (ptr->next->value > value) {
                temp->next = ptr->next;
                ptr->next = temp;
                return;
            }
        }
        ptr->next = temp;
    }
}

void delete_list()
{
    int data;
    struct node* ptr = head, * tmp;

    if (head == NULL) {         // 빈 리스트라면
        printf("Empty List. Return without deleting!\n");
        return;
    }

    printf("Enter data to delete: ");
    scanf("%d", &data);

    if (head->value == data) { // 지울 데이터가 헤드라면
        head = head->next;
        free(ptr);
        return;
    }
    for (ptr = head; ptr->next; ptr = ptr->next) {
        if (ptr->next->value == data) {
            tmp = ptr->next;
            ptr->next = ptr->next->next;
            printf("%d deleted!\n", tmp->value);
            free(tmp);
            return;
        }
    }
    printf("Data not found!\n");
}