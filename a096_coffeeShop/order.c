#include "main.h"

orderNode* orderList = NULL;	// 주문 목록의 헤드 포인터
static int orderNo = 0;	    // 주문 항목에 부여됨(예, 라테 2잔)

char* getMenuName(int menuId)
{
	menuItem* ptr;

	for (ptr = menuItemList; ptr; ptr = ptr->next)
		if (ptr->id == menuId)
			return ptr->menuName;
	printf("해당 메뉴가 없습니다!");
	return NULL;
}

bool isInMenu(int menuId)
{
	menuItem* ptr;

	for (ptr = menuItemList; ptr; ptr = ptr->next)
		if (ptr->id == menuId)
			return true;
	return false;
}

orderNode* insertOrderList(int menuId, int quantity, int price)
{
	orderNode* tmp = (orderNode*)malloc(sizeof(orderNode));
	orderNode* ptr;

	tmp->orderId = ++orderNo;
	tmp->menuId = menuId;
	tmp->price = price;
	tmp->sales = quantity;
	strcpy(tmp->menuName, getMenuName(menuId));
	tmp->next = NULL;

	if (orderList == NULL) {
		orderList = tmp;
	}
	else {
		for (ptr = orderList; ptr->next; ptr = ptr->next)
			;
		ptr->next = tmp;
	}
	return orderList;
}

int getPrice(int menuId)
{
	menuItem* ptr;

	for (ptr = menuItemList; ptr; ptr = ptr->next)
		if (ptr->id == menuId)
			return ptr->price;
	printf("해당 메뉴가 없습니다!");
	return 0;
}

int addOrder(int menuId, int quantity)
{
	int price = getPrice(menuId);

	orderList = insertOrderList(menuId, quantity, price);
	return quantity * price;
}

orderNode* addThisOrder(orderNode* thisOrder, int menuId, int quantity, int price)
{
	orderNode* tmp = NULL, * ptr;

	tmp = malloc(sizeof(orderNode));
	tmp->menuId = menuId;
	strcpy(tmp->menuName, getMenuName(menuId));
	tmp->sales = quantity;
	tmp->price = price;
	tmp->next = NULL;

	if (thisOrder == NULL)
		return tmp;
	else {
		for (ptr = thisOrder; ptr->next; ptr = ptr->next)
			;
		ptr->next = tmp;
		return thisOrder;
	}
}

// 현재 진행중인 주문 목록을 출력합니다.
void printOrder(orderNode* thisOrder)
{
	orderNode* tmp = NULL;
	int totalPrice = 0;

	if (thisOrder != NULL) {
		printf("\n\n\t\t\t\t===  주문 목록 ===\n");
		printf("\n\t\t");
		printf("-------------------------------------------------------");
		printf("\n\t\t번호\t\t음료이름\t\t수량\t   가격");
		printf("\n\t\t");
		printf("-------------------------------------------------------");
		for (tmp = thisOrder; tmp; tmp = tmp->next) {
			printf("\n\t\t%d\t\t%s\t\t%3d\t%7d",
				tmp->menuId, getMenuName(tmp->menuId),
				tmp->sales, tmp->price);
			totalPrice += tmp->price;
		}
		printf("\n\t\t-------------------------------------------------------");
		printf("\n\t\t총액\t\t\t\t\t\t%7d", totalPrice);
		printf("\n\t\t-------------------------------------------------------");
	}
}

// 2번 메뉴(주문)
void order()
{
	menuItem* tmp = menuItemList;
	orderNode* thisOrder = NULL;;
	int menuId, quantity, price;

	while (1) {
		system("cls");
		printf("\n\t\t\t\t=== (2) 주문 메뉴 ===\n");

		showCoffeeMenu();
		printOrder(thisOrder);

		printf("\n\n\t\t\t 주문할 메뉴를 입력하세요(주문 종료 = 0): ");
		scanf("%d", &menuId);
		if (menuId == 0)
			return;
		if (isInMenu(menuId) == false) {
			printf("\n\t\t\t해당 메뉴가 없습니다!");
			Sleep(1000);
			continue;
		}
		printf("\t\t\t 수량을 입력하세요: ");
		scanf("%d", &quantity);
		price = addOrder(menuId, quantity);
		thisOrder = addThisOrder(thisOrder, menuId, quantity, price);
	}
}

// 3번 메뉴(주문 취소)
void deleteOrder()
{
	orderNode* tmp = orderList;
	int id;

	while (1) {
		system("cls");
		printf("\n\n\t\t\t\t===  (3) 주문 취소 ===\n");
		showOrders();

		printf("\n\n\t\t");
		printf("취소할 주문의 번호 입력(메뉴로 돌아가려면 0) : ");
		scanf(" %d", &id);

		if (id == 0 || orderList == NULL) {	// 메인 메뉴로
			return;
		}
		if (orderList->orderId == id) { // 첫번째 주문 취소
			orderList = orderList->next;
			printf("\n\n\t\t주문 번호 %d이(가) 취소되었습니다.", id);
			Sleep(2000);
		}
		else {
			while (tmp->next) {
				if (tmp->next->orderId == id) {
					printf("\n\n\t\t주문번호 %d이(가) 취소되었습니다.", id);
					tmp->next = tmp->next->next;
					Sleep(2000);
					break;
				}
				tmp = tmp->next;
			}
		}
	}
}

// 4번 메뉴(주문 목록 확인)
void showOrderList()
{
	system("cls");

	printf("\n\n\t\t\t\t===  (4) 주문 목록 ===\n");
	showOrders();
	waitZeroInput();
}

void showOrders()
{
	orderNode* tmp = NULL;
	int totalPrice = 0;

	printf("\n\t\t");
	printf("-------------------------------------------------------");
	printf("\n\t\t주문번호\t음료이름\t\t수량\t   가격");
	printf("\n\t\t");
	printf("-------------------------------------------------------");
	for (tmp = orderList; tmp; tmp = tmp->next) {
		printf("\n\t\t%d\t\t%s\t\t%3d\t%7d",
			tmp->orderId, getMenuName(tmp->menuId),
			tmp->sales, tmp->price * tmp->sales);
		totalPrice += tmp->price * tmp->sales;
	}
	printf("\n\t\t-------------------------------------------------------");
	printf("\n\t\t총액\t\t\t\t\t\t%7d", totalPrice);
	printf("\n\t\t-------------------------------------------------------");
}