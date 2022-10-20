#include "main.h"

int main()
{
    system("title Coffee Shop Management System");
    system("mode con: cols=88 lines=40");

    if (passwordCheck() == 0)
        return 0;

    loadCoffeeMenu();        // ���� �忡�� ����
    loadTodaySales();  // ���� �忡�� ����

    mainMenu();        // ���� �޴� �����ֱ�
}

int passwordCheck()
{
    int password;

    printf("\n\t\t\t    Ŀ�Ǽ� �����ý���!");
    printf("\n\n\t\t\t��й�ȣ�� �Է��ϼ���: ");
    scanf("%d", &password);

    if (password == 1234) 	// password�� ���Ͽ��� ó��!(��ȣȭ)
        return 1;
    else {
        printf("\n\t\t\t��й�ȣ�� Ʋ���ϴ�!\n�ý����� �����մϴ�!\n");
        Sleep(1000);
        return 0;
    }
}


// ���Ͽ��� �޴� ������ �о menuItemList�� ����
void loadCoffeeMenu()
{
    FILE* fp;
    menuItem* tmp = menuItemList;
    char line[80], menuName[30];
    int id, price;

    fp = fopen("menu.txt", "r");
    if (fp == NULL) {
        printf("Error(loadMenu): menu.txt ���� ���� ����!");
        return;
    }

    while (fgets(line, 80, fp) != NULL) {
        sscanf(line, "%d,%[^,],%d\n", &id, menuName, &price);
        //printf("%d, %s, %d\n", id, menuName, price);
        insertCoffeeMenu(id, menuName, price);
    }
}

void insertCoffeeMenu(int id, const char* menuName, int price)
{
    menuItem* head;
    menuItem* tmp = (menuItem*)malloc(sizeof(menuItem));

    if (tmp != NULL) {
        tmp->id = id;
        strcpy(tmp->menuName, menuName);
        tmp->price = price;
        tmp->next = NULL;
    }
    else {
        printf("�޸� �Ҵ� ����: insertCoffeeMenu\n");
        return;
    }
    if (menuItemList == NULL) {
        menuItemList = tmp;
    }
    else {
        head = menuItemList;
        while (head->next != NULL)
            head = head->next;
        head->next = tmp;
    }
}