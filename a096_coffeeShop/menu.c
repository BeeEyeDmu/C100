#include "main.h"

menuItem* menuItemList; // 커피 메뉴 연결리스트의 헤드 포인터

void mainMenu()
{
	int choice;
	int s = 0;

	while (1) {
		showMainMenu();
		s = scanf("%d", &choice);

		switch (choice) {
		case 1:	// 커피 메뉴 보기
			showCoffeeMenuList();
			break;
		case 2:	// 주문
			order();
			break;
		case 3: // 주문 취소
			deleteOrder();
			break;
		case 4:	// 주문 목록 확인
			showOrderList();
			break;
		case 5:	// 오늘의 매출
			showSaleToday();
			break;
		case 6:	// 커피 메뉴 추가
			if (addCoffeeMenu() == 1)
				saveMenuFile();
			break;
		case 7:  // 커피 메뉴 삭제
			if (deleteCoffeeMenu() == 1)
				saveMenuFile();
			break;
		case 8:		// 데이터 저장
			backup();
			break;
		case 0:		// 끝내기
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
	printf("\n\t\t\t\t=== 메인 메뉴 ===\n\n");
	printf("\t\t\t 1. 커피 메뉴 보기\n\n");
	printf("\t\t\t 2. 주문\n\n");
	printf("\t\t\t 3. 주문 취소\n\n");
	printf("\t\t\t 4. 주문 목록 확인\n\n");
	printf("\t\t\t 5. 오늘의 매출\n\n");
	printf("\t\t\t 6. 커피 메뉴 추가하기\n\n");
	printf("\t\t\t 7. 커피 메뉴 삭제하기\n\n");
	printf("\t\t\t 8. 데이터 저장\n\n");
	printf("\t\t\t 0. 끝내기\n\n");
	printf("\t\t\t메뉴를 선택해주세요(1~0): ");
}

void showCoffeeMenuList()
{
	system("cls");

	printf("\n\t\t\t\t=== (1) 커피 메뉴 보기 ===\n");
	showCoffeeMenu();

	waitZeroInput();
}

void showCoffeeMenu()
{
	menuItem* tmp = menuItemList;

	printf("\n\t\t");
	printf("-------------------------------------------------------");
	printf("\n\t\t");
	printf("번호\t\t음료이름\t\t\t   가격");
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

	printf("\n\t\t\t시스템을 종료합니다...\n");
	printf("\n\t\t\t데이터를 저장했는지 확인하세요!\n");
	printf("\n\t\t\t지금 종료하시겠습니까?(y/n) : ");
	scanf(" %s", confirm);

	if (!strcmp(confirm, "y"))
		return 1;
	else
		return 0;
}

// 0이 입력될 때까지 화면 유지
void waitZeroInput()
{
	int c = 1;

	printf("\n\n\t\t메인 메뉴로 돌아가려면 0을 누르세요: ");
	while (c != 0)
		scanf(" %d", &c);
}

