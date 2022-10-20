#include "main.h"

void saveMenuFile()
{
	FILE* fp;
	menuItem* tmp = menuItemList;

	fp = fopen("menu.txt", "w");
	if (fp == NULL) {
		printf("Error(saveMenuFile): menu.txt 파일 오픈 에러!");
		return;
	}
	while (tmp != NULL) {
		fprintf(fp, "%d,%s,%d\n", tmp->id, tmp->menuName, tmp->price);
		tmp = tmp->next;
	}
	fclose(fp);
	printf("\n\t\t메뉴가 파일에 저장되었습니다.");
	Sleep(2000);
}

// 오늘 날짜 파일에서 매출 자료를 읽어서 자료구조에 저장함
void loadTodaySales()
{
	FILE* fp;
	char date[20] = __DATE__;  // 미리 정의된 매크로

	strcat(date, ".csv");
	fp = fopen(date, "r");

	if (fp == NULL) {
		printf("\n\t\t저장된 오늘의 매출자료는 없습니다.\n");
		waitZeroInput();
		return;
	}

	char line[80];
	int menuId, price, sales, total;
	char menuName[30];
	int savedCount = 0;	// 저장되었던 매출 건수
	int savedTotal = 0;

	while (fgets(line, 80, fp) != NULL) {
		sscanf(line, "%d,%[^,],%d,%d,%d",
			&menuId, menuName, &price, &sales, &total);
		savedCount++;
		savedTotal += total;
		addOrder(menuId, sales);
	}
	printf("\n\t\t파일에 저장된 %d건, 총 %d원의 매출 자료를 읽어왔습니다.",
		savedCount, savedTotal);
	waitZeroInput();
}

// 메인 메뉴 8(데이터 저장)
void backup()
{
	saleNode* saleToday = NULL;	// saleNode는 메뉴별로 매출액을 저장
	saleNode* p;
	char date[20] = __DATE__;
	orderNode* ptr;
	int totalSaleToday = 0;

	strcat(date, ".csv");
	FILE* fp;
	fp = fopen(date, "w");
	if (fp == NULL) {
		printf("파일 오픈 에러\n");
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
	printf("\n\n\t\t\t%s : 총매출 = %d", date, totalSaleToday);
	printf("\n\n\t\t\tBackup Successfull...");
	waitZeroInput();
}

saleNode* addSales(saleNode* saleToday, orderNode* p)
{
	saleNode* ptr, * tmp;

	// 이미 saleToday에 있는 아이템이라면 수량만 더한다
	for (ptr = saleToday; ptr; ptr = ptr->next)
		if (ptr->menuId == p->menuId) {
			ptr->sales += p->sales;
			return saleToday;
		}

	// saleNode를 하나 만든다
	tmp = (saleNode*)malloc(sizeof(saleNode));
	tmp->menuId = p->menuId;
	strcpy(tmp->menuName, p->menuName);
	tmp->price = p->price;
	tmp->sales = p->sales;
	tmp->next = NULL;

	// 리스트 삽입 연산
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