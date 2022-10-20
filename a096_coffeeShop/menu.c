#include "main.h"

menuItem* menuItemList; // Ŀ�� �޴� ���Ḯ��Ʈ�� ��� ������

void mainMenu()
{
	int choice;
	int s = 0;

	while (1) {
		showMainMenu();
		s = scanf("%d", &choice);

		switch (choice) {
		case 1:	// Ŀ�� �޴� ����
			showCoffeeMenuList();
			break;
		case 2:	// �ֹ�
			order();
			break;
		case 3: // �ֹ� ���
			deleteOrder();
			break;
		case 4:	// �ֹ� ��� Ȯ��
			showOrderList();
			break;
		case 5:	// ������ ����
			showSaleToday();
			break;
		case 6:	// Ŀ�� �޴� �߰�
			if (addCoffeeMenu() == 1)
				saveMenuFile();
			break;
		case 7:  // Ŀ�� �޴� ����
			if (deleteCoffeeMenu() == 1)
				saveMenuFile();
			break;
		case 8:		// ������ ����
			backup();
			break;
		case 0:		// ������
			if (close() == 1)
				return;
			break;
		default:
			break;
		}
	}
}

void showMainMenu()
{
	system("cls");
	printf("\n\t\t\t\t=== ���� �޴� ===\n\n");
	printf("\t\t\t 1. Ŀ�� �޴� ����\n\n");
	printf("\t\t\t 2. �ֹ�\n\n");
	printf("\t\t\t 3. �ֹ� ���\n\n");
	printf("\t\t\t 4. �ֹ� ��� Ȯ��\n\n");
	printf("\t\t\t 5. ������ ����\n\n");
	printf("\t\t\t 6. Ŀ�� �޴� �߰��ϱ�\n\n");
	printf("\t\t\t 7. Ŀ�� �޴� �����ϱ�\n\n");
	printf("\t\t\t 8. ������ ����\n\n");
	printf("\t\t\t 0. ������\n\n");
	printf("\t\t\t�޴��� �������ּ���(1~0): ");
}

void showCoffeeMenuList()
{
	system("cls");

	printf("\n\t\t\t\t=== (1) Ŀ�� �޴� ���� ===\n");
	showCoffeeMenu();

	waitZeroInput();
}

void showCoffeeMenu()
{
	menuItem* tmp = menuItemList;

	printf("\n\t\t");
	printf("-------------------------------------------------------");
	printf("\n\t\t");
	printf("��ȣ\t\t�����̸�\t\t\t   ����");
	printf("\n\t\t");
	printf("-------------------------------------------------------");

	while (tmp != NULL) {
		printf("\n\t\t");
		printf("%d\t\t%-20s\t\t%7d", tmp->id, tmp->menuName, tmp->price);
		tmp = tmp->next;
		printf("\n\t\t");
		printf("-------------------------------------------------------");
	}
}

int close()
{
	char confirm[2];

	printf("\n\t\t\t�ý����� �����մϴ�...\n");
	printf("\n\t\t\t�����͸� �����ߴ��� Ȯ���ϼ���!\n");
	printf("\n\t\t\t���� �����Ͻðڽ��ϱ�?(y/n) : ");
	scanf(" %s", confirm);

	if (!strcmp(confirm, "y"))
		return 1;
	else
		return 0;
}

// 0�� �Էµ� ������ ȭ�� ����
void waitZeroInput()
{
	int c = 1;

	printf("\n\n\t\t���� �޴��� ���ư����� 0�� ��������: ");
	while (c != 0)
		scanf(" %d", &c);
}

