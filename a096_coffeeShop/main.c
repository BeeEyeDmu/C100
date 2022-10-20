#include "main.h"

int main()
{
    system("title Coffee Shop Management System");
    system("mode con: cols=88 lines=40");

    if (passwordCheck() == 0)
        return 0;

    loadCoffeeMenu();        // 다음 장에서 설명
    loadTodaySales();  // 다음 장에서 설명

    mainMenu();        // 메인 메뉴 보여주기
}

int passwordCheck()
{
    int password;

    printf("\n\t\t\t    커피숍 관리시스템!");
    printf("\n\n\t\t\t비밀번호를 입력하세요: ");
    scanf("%d", &password);

    if (password == 1234) 	// password도 파일에서 처리!(암호화)
        return 1;
    else {
        printf("\n\t\t\t비밀번호가 틀립니다!\n시스템을 종료합니다!\n");
        Sleep(1000);
        return 0;
    }
}


// 파일에서 메뉴 정보를 읽어서 menuItemList에 저장
void loadCoffeeMenu()
{
    FILE* fp;
    menuItem* tmp = menuItemList;
    char line[80], menuName[30];
    int id, price;

    fp = fopen("menu.txt", "r");
    if (fp == NULL) {
        printf("Error(loadMenu): menu.txt 파일 오픈 에러!");
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
        printf("메모리 할당 에러: insertCoffeeMenu\n");
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