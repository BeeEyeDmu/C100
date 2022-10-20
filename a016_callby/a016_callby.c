#include <stdio.h>

// call by value
void swap(int x, int y)
{
	int tmp;

	tmp = x;
	x = y;
	y = tmp;
}

// call by reference
void swap2(int* px, int* py)
{
	int tmp;

	tmp = *px;
	*px = *py;
	*py = tmp;
}

int main()
{
	int x = 3;
	int y = 4;

	swap(x, y);
	printf("swap() ȣ�� �� : x=%d y=%d\n", x, y);

	swap2(&x, &y);
	printf("swap2() ȣ�� �� : x=%d y=%d\n", x, y);
}