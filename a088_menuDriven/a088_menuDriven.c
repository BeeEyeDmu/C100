#define _CRT_SECURE_NO_WARNINGS
#define PI	3.141592
#include <stdio.h>

void menu()
{
	printf("== �޴� ==\n");
	printf(" 1. ���� ����\n");
	printf(" 2. ���簢���� ����\n");
	printf(" 3. ���� ����\n");
	printf(" 4. ���α׷� ����\n");
	printf("���ϴ� �޴��� �����ϼ���: ");
}

void circleMenu()
{
	float result, num;

	printf("���� �������� �Է��ϼ���: ");
	scanf("%f", &num);
	result = PI * num * num;
	printf("���� ���� = %f\n", result);
}

void squareMenu()
{
	float result, side;

	printf("���簢���� �Ѻ��� ũ�⸦ �Է��ϼ���: ");
	scanf("%f", &side);
	result = side * side;
	printf("���簢���� ���� = %f\n", result);
}

void sphareMenu()
{
	float result, radius;

	printf("���� �������� �Է��ϼ���: ");
	scanf("%f", &radius);
	result = 4 * (PI * radius * radius);
	printf("���� ǥ���� = %f\n", result);
}

int main()
{
	int choice;

	do {
		menu();
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			circleMenu();
			break;
		case 2:
			squareMenu();
			break;
		case 3:
			sphareMenu();
			break;
		default:
			break;
		}
	} while (choice != 4);
}