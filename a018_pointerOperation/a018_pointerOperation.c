#include <stdio.h>

int main()
{
	int a = 10;
	int b = 20;
	int c[5] = { 1,2,3,4,5 };

	int* pa = &a;
	int* pb = &b;
	int* pc;

	pc = c + 2;
	printf("[%p] %d \n", pc, *pc);

	pc = pc - 1;
	printf("[%p] %d \n", pc, *pc);

	pc = c;

	int* pd = &c[4];

	int cnt = pd - pc;
	printf("[%p] [%p] %d\n", pc, pd, cnt);
}