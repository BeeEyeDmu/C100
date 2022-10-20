#include "main.h"

orderNode* orderList = NULL;	// �ֹ� ����� ��� ������
static int orderNo = 0;	    // �ֹ� �׸� �ο���(��, ���� 2��)

char* getMenuName(int menuId)
{
	menuItem* ptr;

	for (ptr = menuItemList; ptr; ptr = ptr->next)
		if (ptr->id == menuId)
			return ptr->menuName;
	printf("�ش� �޴��� �����ϴ�!");
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
	printf("�ش� �޴��� �����ϴ�!");
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

// ���� �������� �ֹ� ����� ����մϴ�.
void printOrder(orderNode* thisOrder)
{
	orderNode* tmp = NULL;
	int totalPrice = 0;

	if (thisOrder != NULL) {
		printf("\n\n\t\t\t\t===  �ֹ� ��� ===\n");
		printf("\n\t\t");
		printf("-------------------------------------------------------");
		printf("\n\t\t��ȣ\t\t�����̸�\t\t����\t   ����");
		printf("\n\t\t");
		printf("-------------------------------------------------------");
		for (tmp = thisOrder; tmp; tmp = tmp->next) {
			printf("\n\t\t%d\t\t%s\t\t%3d\t%7d",
				tmp->menuId, getMenuName(tmp->menuId),
				tmp->sales, tmp->price);
			totalPrice += tmp->price;
		}
		printf("\n\t\t-------------------------------------------------------");
		printf("\n\t\t�Ѿ�\t\t\t\t\t\t%7d", totalPrice);
		printf("\n\t\t-------------------------------------------------------");
	}
}

// 2�� �޴�(�ֹ�)
void order()
{
	menuItem* tmp = menuItemList;
	orderNode* thisOrder = NULL;;
	int menuId, quantity, price;

	while (1) {
		system("cls");
		printf("\n\t\t\t\t=== (2) �ֹ� �޴� ===\n");

		showCoffeeMenu();
		printOrder(thisOrder);

		printf("\n\n\t\t\t �ֹ��� �޴��� �Է��ϼ���(�ֹ� ���� = 0): ");
		scanf("%d", &menuId);
		if (menuId == 0)
			return;
		if (isInMenu(menuId) == false) {
			printf("\n\t\t\t�ش� �޴��� �����ϴ�!");
			Sleep(1000);
			continue;
		}
		printf("\t\t\t ������ �Է��ϼ���: ");
		scanf("%d", &quantity);
		price = addOrder(menuId, quantity);
		thisOrder = addThisOrder(thisOrder, menuId, quantity, price);
	}
}

// 3�� �޴�(�ֹ� ���)
void deleteOrder()
{
	orderNode* tmp = orderList;
	int id;

	while (1) {
		system("cls");
		printf("\n\n\t\t\t\t===  (3) �ֹ� ��� ===\n");
		showOrders();

		printf("\n\n\t\t");
		printf("����� �ֹ��� ��ȣ �Է�(�޴��� ���ư����� 0) : ");
		scanf(" %d", &id);

		if (id == 0 || orderList == NULL) {	// ���� �޴���
			return;
		}
		if (orderList->orderId == id) { // ù��° �ֹ� ���
			orderList = orderList->next;
			printf("\n\n\t\t�ֹ� ��ȣ %d��(��) ��ҵǾ����ϴ�.", id);
			Sleep(2000);
		}
		else {
			while (tmp->next) {
				if (tmp->next->orderId == id) {
					printf("\n\n\t\t�ֹ���ȣ %d��(��) ��ҵǾ����ϴ�.", id);
					tmp->next = tmp->next->next;
					Sleep(2000);
					break;
				}
				tmp = tmp->next;
			}
		}
	}
}

// 4�� �޴�(�ֹ� ��� Ȯ��)
void showOrderList()
{
	system("cls");

	printf("\n\n\t\t\t\t===  (4) �ֹ� ��� ===\n");
	showOrders();
	waitZeroInput();
}

void showOrders()
{
	orderNode* tmp = NULL;
	int totalPrice = 0;

	printf("\n\t\t");
	printf("-------------------------------------------------------");
	printf("\n\t\t�ֹ���ȣ\t�����̸�\t\t����\t   ����");
	printf("\n\t\t");
	printf("-------------------------------------------------------");
	for (tmp = orderList; tmp; tmp = tmp->next) {
		printf("\n\t\t%d\t\t%s\t\t%3d\t%7d",
			tmp->orderId, getMenuName(tmp->menuId),
			tmp->sales, tmp->price * tmp->sales);
		totalPrice += tmp->price * tmp->sales;
	}
	printf("\n\t\t-------------------------------------------------------");
	printf("\n\t\t�Ѿ�\t\t\t\t\t\t%7d", totalPrice);
	printf("\n\t\t-------------------------------------------------------");
}