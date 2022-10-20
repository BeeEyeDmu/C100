#include "main.h"

void saveMenuFile()
{
	FILE* fp;
	menuItem* tmp = menuItemList;

	fp = fopen("menu.txt", "w");
	if (fp == NULL) {
		printf("Error(saveMenuFile): menu.txt ���� ���� ����!");
		return;
	}
	while (tmp != NULL) {
		fprintf(fp, "%d,%s,%d\n", tmp->id, tmp->menuName, tmp->price);
		tmp = tmp->next;
	}
	fclose(fp);
	printf("\n\t\t�޴��� ���Ͽ� ����Ǿ����ϴ�.");
	Sleep(2000);
}

// ���� ��¥ ���Ͽ��� ���� �ڷḦ �о �ڷᱸ���� ������
void loadTodaySales()
{
	FILE* fp;
	char date[20] = __DATE__;  // �̸� ���ǵ� ��ũ��

	strcat(date, ".csv");
	fp = fopen(date, "r");

	if (fp == NULL) {
		printf("\n\t\t����� ������ �����ڷ�� �����ϴ�.\n");
		waitZeroInput();
		return;
	}

	char line[80];
	int menuId, price, sales, total;
	char menuName[30];
	int savedCount = 0;	// ����Ǿ��� ���� �Ǽ�
	int savedTotal = 0;

	while (fgets(line, 80, fp) != NULL) {
		sscanf(line, "%d,%[^,],%d,%d,%d",
			&menuId, menuName, &price, &sales, &total);
		savedCount++;
		savedTotal += total;
		addOrder(menuId, sales);
	}
	printf("\n\t\t���Ͽ� ����� %d��, �� %d���� ���� �ڷḦ �о�Խ��ϴ�.",
		savedCount, savedTotal);
	waitZeroInput();
}

// ���� �޴� 8(������ ����)
void backup()
{
	saleNode* saleToday = NULL;	// saleNode�� �޴����� ������� ����
	saleNode* p;
	char date[20] = __DATE__;
	orderNode* ptr;
	int totalSaleToday = 0;

	strcat(date, ".csv");
	FILE* fp;
	fp = fopen(date, "w");
	if (fp == NULL) {
		printf("���� ���� ����\n");
		return;
	}

	for (ptr = orderList; ptr; ptr = ptr->next) {
		saleToday = addSales(saleToday, ptr);
	}

	for (p = saleToday; p; p = p->next) {
		fprintf(fp, "%d,%s,%d,%d,%d\n", p->menuId, p->menuName,
			p->price, p->sales, p->price * p->sales);
		totalSaleToday += p->price * p->sales;
	}

	fclose(fp);
	printf("\n\n\t\t\t%s : �Ѹ��� = %d", date, totalSaleToday);
	printf("\n\n\t\t\tBackup Successfull...");
	waitZeroInput();
}

saleNode* addSales(saleNode* saleToday, orderNode* p)
{
	saleNode* ptr, * tmp;

	// �̹� saleToday�� �ִ� �������̶�� ������ ���Ѵ�
	for (ptr = saleToday; ptr; ptr = ptr->next)
		if (ptr->menuId == p->menuId) {
			ptr->sales += p->sales;
			return saleToday;
		}

	// saleNode�� �ϳ� �����
	tmp = (saleNode*)malloc(sizeof(saleNode));
	tmp->menuId = p->menuId;
	strcpy(tmp->menuName, p->menuName);
	tmp->price = p->price;
	tmp->sales = p->sales;
	tmp->next = NULL;

	// ����Ʈ ���� ����
	if (saleToday == NULL) {
		saleToday = tmp;
	}
	else {
		for (ptr = saleToday; ptr->next; ptr = ptr->next)
			;
		ptr->next = tmp;
	}
	return saleToday;
}