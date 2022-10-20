#include "main.h"

// 5�� �޴�(������ ����)
void showSaleToday()
{
	system("cls");
	printf("\n\t\t\t\t=== (5) ������ ���� ===\n");
	printf("\n\t\t\t���� ������� ���� : %d��\n", totalSales());
	waitZeroInput();
}

// ���� orderList�� �ִ� ������ ����
int totalSales()
{
	orderNode* ptr;
	int totalSales = 0;

	for (ptr = orderList; ptr; ptr = ptr->next)
		totalSales += (int)(ptr->price * ptr->sales);
	return totalSales;
}

// 6�� �޴�(Ŀ�� �޴� �߰�)
int addCoffeeMenu()
{
	int id, price;
	char menuName[30];

	system("cls");
	printf("\n\t\t\t\t=== (6) ���ο� �޴� �߰� ===\n");
	showCoffeeMenu();

	printf("\n\n\t\t�߰��� �޴��� ��ȣ �Է�(�޴��� ���ư����� 0) : ");
	scanf("%d", &id);

	if (id == 0)	// �߰� ���� ���� �޴���
		return 0;

	printf("\n\t\t�߰��� �޴��� �̸� �Է� : ");
	scanf(" %[^\n]", menuName);  // ���� ��ĭ�� white space�� skip

	printf("\n\t\t�߰��� �޴��� ���� �Է� : ");
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
//		printf("�޸� �Ҵ� ����: insertCoffeeMenu\n");
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

// 7�� �޴�(Ŀ�� �޴� ����)
int deleteCoffeeMenu()
{
	int id, result;

	system("cls");
	printf("\n\t\t\t\t=== (7) Ŀ�� �޴� ���� ===\n");
	showCoffeeMenu();

	printf("\n\n\t\t������ �޴� ��ȣ �Է�(���� �޴��� ���ư����� 0) : ");
	scanf("%d", &id);
	if (id == 0)
		return 0;

	result = deleteMenuList(id);

	system("cls");
	printf("\n\t\t\t\t=== (7) �޴� ���� ===\n");
	showCoffeeMenu();

	if (result == 1)
		printf("\n\n\t\t%d�� �޴��� �����Ǿ����ϴ�.", id);

	waitZeroInput();
	return 1;
}

// menuItemList���� ��带 ����
int deleteMenuList(int id)
{
	menuItem* tmp = menuItemList;

	if (tmp->id == id)
		menuItemList = tmp->next;
	else {
		while (tmp->next != NULL && tmp->next->id != id)
			tmp = tmp->next;
		if (tmp->next == NULL) { // ������ ã�� id�� ���� ��
			printf("\n\n\t\t\t�Էµ� ��ȣ�� �޴��� �����ϴ�!");
			Sleep(1000);
			return 0;
		}
		else {
			tmp->next = tmp->next->next;
			return 1;
		}
	}
}