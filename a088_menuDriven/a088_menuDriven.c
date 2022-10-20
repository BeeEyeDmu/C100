#define _CRT_SECURE_NO_WARNINGS
#define PI	3.141592
#include <stdio.h>

void menu()
{
	printf("== 메뉴 ==\n");
	printf(" 1. 원의 면적\n");
	printf(" 2. 정사각형의 면적\n");
	printf(" 3. 구의 면적\n");
	printf(" 4. 프로그램 종료\n");
	printf("원하는 메뉴를 선택하세요: ");
}

void circleMenu()
{
	float result, num;

	printf("원의 반지름을 입력하세요: ");
	scanf("%f", &num);
	result = PI * num * num;
	printf("원의 면적 = %f\n", result);
}

void squareMenu()
{
	float result, side;

	printf("정사각형의 한변의 크기를 입력하세요: ");
	scanf("%f", &side);
	result = side * side;
	printf("정사각형의 면적 = %f\n", result);
}

void sphareMenu()
{
	float result, radius;

	printf("구의 반지름을 입력하세요: ");
	scanf("%f", &radius);
	result = 4 * (PI * radius * radius);
	printf("구의 표면적 = %f\n", result);
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