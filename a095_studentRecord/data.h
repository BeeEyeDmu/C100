// 커피 메뉴를 저장하는 구조체
typedef struct menuItem {
	int id;					// 메뉴 번호
	char menuName[30];		// 메뉴 이름
	int price;				// 단가	
	struct menuItem* next;
} menuItem;

// 주문을 저장하는 구조체
typedef struct orderNode {
	int orderId;			// 주문 번호
	int menuId;				// 메뉴 번호
	char menuName[30];		// 메뉴 이름
	int price;				// 단가
	int sales;  			// 판매량
	struct orderNode* next;
} orderNode;

// 매출을 저장하는 구조체(메뉴별로 저장)
typedef struct saleNode {
	int menuId;				// 메뉴 번호
	char menuName[30];		// 메뉴 이름
	int price;				// 단가
	int sales;				// 판매량
	struct saleNode* next;
} saleNode;

