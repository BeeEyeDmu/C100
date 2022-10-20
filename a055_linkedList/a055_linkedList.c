#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void append();          // ����Ʈ�� �ڿ� �߰�
void insert();          // ����Ʈ�� �� �տ� �߰�
void insert_pos();      // Ư�� ��ġ�� �߰�
void display();         // ����Ʈ ���
void delete_begin();    // ����Ʈ�� �� ���� ����
void delete_end();      // ����Ʈ�� �� �ڸ� ����
void delete_pos();      // ����Ʈ�� Ư�� ��ġ�� ����

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
        printf(" 5.Delete beginning\n");
        printf(" 6.Delete end\n");
        printf(" 7.Delete position\n");
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
        case 5:
            delete_begin();
            break;
        case 6:
            delete_end();
            break;
        case 7:
            delete_pos();
            break;
        case 0:
            exit(0);
            break;
        }
    }
}

void append()   // �� �ڿ� �߰�
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

void insert()   // �� �տ� �߰�
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

void insert_pos()  // Ư�� ��ġ�� �߰�
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

void display()  // ����Ʈ ���
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

void delete_begin() // ����Ʈ�� �� ���� ����
{
    struct node* ptr = head;

    if (ptr == NULL) {
        printf("List is Empty!\n");
        return;
    }
    else {
        head = head->next;
        printf("The deleted node is :%d\n", ptr->value);
        free(ptr);
    }
}

void delete_end() // ����Ʈ�� �� �ڸ� ����
{
    struct node* temp = NULL, * ptr = NULL;

    if (head == NULL) {
        printf("List is Empty!\n");
        exit(0);
    }
    else if (head->next == NULL) { // �ϳ��� ��常 �ִ� ���    
        ptr = head;
        head = NULL;
        printf("The deleted node is:%d\n", ptr->value);
        free(ptr);
    }
    else {
        ptr = head;
        while (ptr->next != NULL) {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        printf("\nThe deleted node is:%d\n", ptr->value);
        free(ptr);
    }
}

void delete_pos() // ����Ʈ�� Ư�� ��ġ�� ����
{
    int i, pos;
    struct node* temp = NULL, * ptr = NULL;

    if (head == NULL) {
        printf("List is Empty!\n");
        exit(0);
    }
    else {
        printf("Enter the position to delete: ");
        scanf("%d", &pos);
        if (pos == 0)
        {
            ptr = head;
            head = head->next;
            printf("The deleted node is: %d\n", ptr->value);
            free(ptr);
        }
        else {
            ptr = head;
            for (i = 0; i < pos; i++) {
                temp = ptr;
                ptr = ptr->next;
                if (ptr == NULL) {
                    printf("Position not Found!\n");
                    return;
                }
            }
            temp->next = ptr->next;
            printf("The deleted node is:%d\n", ptr->value);
            free(ptr);
        }
    }
}