// Ŀ�� �޴��� �����ϴ� ����ü
typedef struct menuItem {
	int id;					// �޴� ��ȣ
	char menuName[30];		// �޴� �̸�
	int price;				// �ܰ�	
	struct menuItem* next;
} menuItem;

// �ֹ� ������ �����ϴ� ����ü
typedef struct orderNode {
	int orderId;			// �ֹ� ��ȣ
	int menuId;				// �޴� ��ȣ
	char menuName[30];		// �޴� �̸�
	int price;				// �ܰ�
	int sales;  			// �Ǹŷ�
	struct orderNode* next;
} orderNode;

// ���� ������ �����ϴ� ����ü(Ŀ�� �޴����� ����)
typedef struct saleNode {
	int menuId;				// �޴� ��ȣ
	char menuName[30];		// �޴� �̸�
	int price;				// �ܰ�
	int sales;				// �Ǹŷ�
	struct saleNode* next;
} saleNode;

