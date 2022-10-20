#include "main.h"

// 5번 메뉴(오늘의 매출)
void showSaleToday()
{
	system("cls");
	printf("\n\t\t\t\t=== (5) 오늘의 매출 ===\n");
	printf("\n\t\t\t오늘 현재까지 매출 : %d원\n", totalSales());
	waitZeroInput();
}

// 현재 orderList에 있는 매출의 총합
int totalSales()
{
	orderNode* ptr;
	int totalSales = 0;

	for (ptr = orderList; ptr; ptr = ptr->next)
		totalSales += (int)(ptr->price * ptr->sales);
	return totalSales;
}

// 6번 메뉴(커피 메뉴 추가)
int addCoffeeMenu()
{
	int id, price;
	char menuName[30];

	system("cls");
	printf("\n\t\t\t\t=== (6) 새로운 메뉴 추가 ===\n");
	showCoffeeMenu();

	printf("\n\n\t\t추가할 메뉴의 번호 입력(메뉴로 돌아가려면 0) : ");
	scanf("%d", &id);

	if (id == 0)	// 추가 없이 메인 메뉴로
		return 0;

	printf("\n\t\t추가할 메뉴의 이름 입력 : ");
	scanf(" %[^\n]", menuName);  // 앞의 빈칸이 white space를 skip

	printf("\n\t\t추가할 메뉴의 가격 입력 : ");
	scanf("%d", &price);

	insertCoffeeMenu(id, menuName, price);
	return 1;
}

//void insertCoffeeMenu(int id, const char* menuName, int price)
//{
//	menuItem* head;
//	menuItem* tmp = (menuItem*)malloc(sizeof(menuItem));
//
//	if (tmp != NULL) {
//		tmp->id = id;
//		strcpy(tmp->menuName, menuName);
//		tmp->price = price;
//		tmp->next = NULL;
//	}
//	else {
//		printf("메모리 할당 에러: insertCoffeeMenu\n");
//		return;
//	}
//	if (menuItemList == NULL) {
//		menuItemList = tmp;
//	}
//	else {
//		head = menuItemList;
//		while (head->next != NULL)
//			head = head->next;
//		head->next = tmp;
//	}
//}

// 7번 메뉴(커피 메뉴 삭제)
int deleteCoffeeMenu()
{
	int id, result;

	system("cls");
	printf("\n\t\t\t\t=== (7) 커피 메뉴 삭제 ===\n");
	showCoffeeMenu();

	printf("\n\n\t\t삭제할 메뉴 번호 입력(메인 메뉴로 돌아가려면 0) : ");
	scanf("%d", &id);
	if (id == 0)
		return 0;

	result = deleteMenuList(id);

	system("cls");
	printf("\n\t\t\t\t=== (7) 메뉴 삭제 ===\n");
	showCoffeeMenu();

	if (result == 1)
		printf("\n\n\t\t%d번 메뉴가 삭제되었습니다.", id);

	waitZeroInput();
	return 1;
}

// menuItemList에서 노드를 삭제
int deleteMenuList(int id)
{
	menuItem* tmp = menuItemList;

	if (tmp->id == id)
		menuItemList = tmp->next;
	else {
		while (tmp->next != NULL && tmp->next->id != id)
			tmp = tmp->next;
		if (tmp->next == NULL) { // 끝까지 찾는 id가 없을 때
			printf("\n\n\t\t\t입력된 번호의 메뉴가 없습니다!");
			Sleep(1000);
			return 0;
		}
		else {
			tmp->next = tmp->next->next;
			return 1;
		}
	}
}